#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#include "console_draw3.h"
#include "kb_input2.h"
#include "image.h"
#include "font.h"
#include "audio.h"

void Hitvoice()
{
    Audio Hit_music;
    openAudioFile("sounds\\Hit.wav", &Hit_music);
    playAudio (&Hit_music);
}

void Dievoice()
{
    Audio Die_music;
    openAudioFile("sounds\\Hithurt.wav", &Die_music);
    playAudio (&Die_music);
}
