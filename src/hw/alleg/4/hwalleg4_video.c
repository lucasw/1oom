#include "config.h"

#include <stdio.h>
#include <string.h>

#include "types.h"
#include <allegro.h>

#include "hw.h"
#include "hwalleg_video.h"
#include "hwalleg_mouse.h"
#include "hwalleg_opt.h"
#include "lib.h"
#include "log.h"

/* -------------------------------------------------------------------------- */

/* double buffering + 2 aux buffers */
#define NUM_VIDEOBUF    4

static struct alleg_video_s {
    BITMAP *bm;

    void (*render)(int bufi);
    void (*update)(void);
    void (*setpal)(uint8_t *pal, int first, int num);

    /* buffers used by UI */
    uint8_t *buf[NUM_VIDEOBUF];
    int bufw;
    int bufh;
    int bufi;

    /* palette as set by UI, 6bpp */
    uint8_t pal[256 * 3];
    RGB color[256];
} video = { 0 };

/* -------------------------------------------------------------------------- */

static void video_render_8bpp(int bufi)
{
    BITMAP *bm = video.bm;
    uint8_t *p, *q = video.buf[bufi];
    for (int y = 0; y < video.bufh; ++y) {
        p = bm->line[y];
        memcpy(p, q, video.bufw);
        q += video.bufw;
    }
}

static void video_update_8bpp(void)
{
    blit(video.bm, screen, 0, 0, 0, 0, video.bufw, video.bufh);
}

static void video_setpal_8bpp(uint8_t *pal, int first, int num)
{
    memcpy(&video.pal[first * 3], pal, num * 3);
    for (int i = first; i < (first + num); ++i) {
        video.color[i].r = *pal++;
        video.color[i].g = *pal++;
        video.color[i].b = *pal++;
    }
    set_palette_range(video.color, first, first + num - 1, 1);
}

/* -------------------------------------------------------------------------- */

int hw_video_init(int w, int h)
{
    hw_mouse_set_limits(w, h);
    video.bufw = w;
    video.bufh = h;
    video.render = video_render_8bpp;
    video.update = video_update_8bpp;
    video.setpal = video_setpal_8bpp;
    set_color_depth(8);
    if (set_gfx_mode(GFX_AUTODETECT, w, h, 0, 0) != 0) {
        log_error("set_gfx_mode(..., %i, %i, 0, 0) failed!\n", w, h);
        return -1;
    }
    hw_video_in_gfx = true;
    video.bm = create_bitmap(w, h);
    for (int i = 0; i < NUM_VIDEOBUF; ++i) {
        video.buf[i] = lib_malloc(w * h);
    }
    video.bufi = 0;
    memset(video.pal, 0, sizeof(video.pal));
    hw_video_refresh_palette();
    return 0;
}

void hw_video_shutdown(void)
{
    if (video.bm) {
        destroy_bitmap(video.bm);
        video.bm = NULL;
    }
    for (int i = 0; i < NUM_VIDEOBUF; ++i) {
        lib_free(video.buf[i]);
        video.buf[i] = NULL;
    }
}

void hw_video_input_grab(bool grab)
{
}

#include "hwalleg_video.c"
