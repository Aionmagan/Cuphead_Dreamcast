#include "Renderer.h"
#include <dc/pvr.h>

void Render::Init()
{
    pvr_init_defaults();
	pvr_set_bg_color(0.8f, 1.0f, 0.8f);
}

void Render::ShutDown()
{
    pvr_mem_reset();
	pvr_shutdown();
}

void Render::TransparentBegin()
{
    pvr_wait_ready();
	pvr_scene_begin();
	pvr_list_begin(PVR_LIST_TR_POLY);
}

void Render::OpequeBegin()
{
    //maybe adding later
}

void Render::Finish()
{
    pvr_scene_finish();
}