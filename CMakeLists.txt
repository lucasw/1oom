cmake_minimum_required(VERSION 3.5)

project(1oom)

message(WARNING ${CMAKE_CURRENT_SOURCE_DIR}/src)

find_package(SDL2 REQUIRED CONFIG REQUIRED)  # COMPONENTS SDL2)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/src/game
  ${CMAKE_CURRENT_SOURCE_DIR}/src/hw/sdl
  ${CMAKE_CURRENT_SOURCE_DIR}/src/hw/sdl/2
  ${CMAKE_CURRENT_SOURCE_DIR}/src/os/unix
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/classic
  ${SDL2_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}
  src/hw/sdl/2/hwsdl2_audio.c
  src/hw/sdl/2/hwsdl2.c
  src/hw/sdl/2/hwsdl2_mouse.c
  src/hw/sdl/2/hwsdl2_opt.c
  src/hw/sdl/2/hwsdl2_video.c

  src/os/unix/os.c

  src/cfg.c
  src/fmt_mus.c
  src/fmt_pic.c
  src/fmt_sfx.c
  src/font8x8.c
  src/font8x8_draw.c
  src/gfxaux.c
  # src/gfxconv.c
  src/kbd.c
  src/lbx.c
  # src/lbxedit.c
  src/lbxfont.c
  src/lbxgfx.c
  src/lbxpal.c
  # src/lbxview.c
  src/lib.c
  src/log.c
  src/main.c
  src/menu.c
  src/mouse.c
  src/options.c
  src/palette.c
  src/pbx.c
  # src/pbxdump.c
  # src/pbxmake.c
  src/rnd.c
  # src/saveconv.c
  src/util.c
  src/util_cstr.c
  src/util_math.c

  src/game/game_aux.c
  src/game/game_tech.c
  src/game/game_battle_human.c
  src/game/game_nebula.c
  src/game/game_stat.c
  src/game/game_nump.c
  src/game/game_fleet.c
  src/game/game_ai.c
  src/game/game_misc.c
  src/game/game_turn_start.c
  src/game/game_spy.c
  src/game/game_ai_classic.c
  src/game/game_shipdesign.c
  src/game/game_event.c
  src/game/game_diplo.c
  src/game/game_cheat.c
  src/game/game_turn.c
  src/game/game_str_shipnames.c
  src/game/game_str.c
  src/game/game_news.c
  src/game/game_election.c
  src/game/game_parsed.c
  src/game/game_audience.c
  src/game/game.c
  src/game/game_new.c
  src/game/game_num.c
  src/game/game_save.c
  src/game/game_planet.c
  src/game/game_debug.c
  src/game/game_ground.c
  src/game/game_shiptech.c
  src/game/game_battle.c
  src/game/game_bomb.c
  src/game/game_strp.c
  src/game/game_design.c

  src/ui/classic/uicopyprotection.c
  src/ui/classic/uistarmap.c
  src/ui/classic/uiswitch.c
  src/ui/classic/uiturn.c
  src/ui/classic/uibasescrap.c
  src/ui/classic/uiplanets.c
  src/ui/classic/uibattlepre.c
  src/ui/classic/uiload.c
  src/ui/classic/uimsgfilter.c
  src/ui/classic/uiraces.c
  src/ui/classic/uiempirereport.c
  src/ui/classic/uitech.c
  src/ui/classic/uistarmap_trans.c
  src/ui/classic/uihelp.c
  src/ui/classic/uiobj.c
  src/ui/classic/uistarmap_common.c
  src/ui/classic/uisearch.c
  src/ui/classic/uidraw.c
  src/ui/classic/uispecs.c
  src/ui/classic/uinewtech.c
  src/ui/classic/uispy_esp.c
  src/ui/classic/uinewgame.c
  src/ui/classic/uistarmap_transport.c
  src/ui/classic/uidelay.c
  src/ui/classic/uistarmap_reloc.c
  src/ui/classic/uiaudience.c
  src/ui/classic/uicursor.c
  src/ui/classic/uilanding.c
  src/ui/classic/uiclassic.c
  src/ui/classic/uistarmap_orbit_en.c
  src/ui/classic/uigovern.c
  src/ui/classic/uistarview.c
  src/ui/classic/uicaught.c
  src/ui/classic/uixtramenu.c
  src/ui/classic/uidesign.c
  src/ui/classic/uisound.c
  src/ui/classic/uispy_sab.c
  src/ui/classic/uielection.c
  src/ui/classic/uiintro.c
  src/ui/classic/uigameopts.c
  src/ui/classic/uinews.c
  src/ui/classic/uiexplore.c
  src/ui/classic/uimainmenu.c
  src/ui/classic/uinewships.c
  src/ui/classic/uistarmap_enroute.c
  src/ui/classic/uistarmap_ships.c
  src/ui/classic/uibattle.c
  src/ui/classic/uiending.c
  src/ui/classic/uipal.c
  src/ui/classic/uibomb.c
  src/ui/classic/uisave.c
  src/ui/classic/uifleet.c
  src/ui/classic/uiempirestatus.c
  src/ui/classic/uigmap.c
  src/ui/classic/uistarmap_orbit_own.c
  src/ui/classic/uiground.c
  src/ui/classic/uigame.c
)

# target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})
