#include "global.h"
#include "constants/species.h"
#include "malloc.h"
#include "main.h"
#include "task.h"
#include "palette.h"
#include "menu.h"
#include "window.h"
#include "text_window.h"
#include "event_data.h"
#include "string_util.h"
#include "script.h"
#include "overworld.h"
#include "field_fadetransition.h"
#include "field_weather.h"
#include "map_obj_80688E4.h"
#include "field_player_avatar.h"
#include "item.h"
#include "wild_encounter.h"
#include "help_system.h"
#include "unk_8159F40.h"
#include "pokemon_storage_system.h"
#include "save.h"
#include "quest_log.h"

u8 gUnknown_3005E88;

struct UnkStruct_203AE94
{
    u8 unk_0_0:4;
    u8 unk_0_4:2;
    u8 unk_0_6:2;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
};

struct UnkStruct_203AE98
{
    u8 filler_0[6];
    u8 unk_6;
};

extern u16 gUnknown_20371F8[];

EWRAM_DATA u8 gUnknown_203ADF8 = 0;
EWRAM_DATA u8 gUnknown_203ADF9 = 0;
EWRAM_DATA u8 gUnknown_203ADFA = 0;
EWRAM_DATA u16 gUnknown_203ADFC = 0;
EWRAM_DATA u8 gUnknown_203ADFE[3];
EWRAM_DATA void * gUnknown_203AE04 = NULL;
EWRAM_DATA u16 * gUnknown_203AE08 = NULL;
EWRAM_DATA void * gUnknown_203AE0C[32] = {NULL};
EWRAM_DATA void (* gUnknown_203AE8C)(void) = 0;
EWRAM_DATA u16 *gUnknown_203AE90 = NULL;
EWRAM_DATA struct UnkStruct_203AE94 gUnknown_203AE94 = {0};
EWRAM_DATA struct UnkStruct_203AE98 gUnknown_203AE98[32] = {0};
EWRAM_DATA u16 gUnknown_203AF98 = 0;

EWRAM_DATA u16 gUnknown_203B044[2] = {0};

void sub_8110A00(void);
void sub_8110A3C(void);
void sub_8110BB0(u8);
void sub_8110BE8(u8);
void sub_8110E3C(void);
void sub_8110D94(void);
void sub_8110E20(void);
void sub_8110D48(u8);
u8 sub_8110E68(struct UnkStruct_203AE98 *);
void sub_8110F90(u8);
void sub_8111150(u8);
void sub_8111368(void);
void sub_81115E8(void);
u16 sub_8111618(void);
u16 sub_811164C(void);
void sub_8111688(void);
void sub_811175C(u8, struct UnkStruct_203AE98 *);
void sub_81118F4(s8);
void sub_8111914(void);
void sub_8111984(void);
void sub_8111A34(u8);
void sub_8111AD8(void);
void sub_8111B80(void);
u8 sub_8111BD4(void);
void sub_8111D10(void);
void sub_8111D90(u8);
void sub_8111E20(void);
void sub_8111E64(s8);
void sub_8111E84(void);
bool8 sub_8111F60(void);
void sub_8111F8C(u8);
void sub_8111FCC(u8);
void sub_8112364(void);
void sub_8112888(u8);
void sub_8112940(u8, struct UnkStruct_203AE98 *, u16);
void sub_811381C(void);
void sub_81138F8(void);
void * sub_8113A78(void *, void **);
void sub_8113ABC(void *);
bool8 sub_8113AE8(void *);
bool8 sub_8113B44(void *);
void sub_8113B88(void);
void sub_8113BD8(void);
void * sub_8113BF4(void *);
void * sub_8113C20(void *, struct UnkStruct_203AE98 *);
void * sub_8113C8C(void *, struct UnkStruct_203AE98 *);
void * sub_8113CC8(void *, struct UnkStruct_203AE98 *);
void * sub_8113D08(void *, struct UnkStruct_203AE98 *);
void * sub_8113D48(void *, struct UnkStruct_203AE98 *);
void * sub_8113D94(void *, struct UnkStruct_203AE98 *);

extern const u8 gUnknown_841A155[];

const struct WindowTemplate gUnknown_845661C[3] = {
    { 0, 0,  0, 30, 2, 15, 0x0e9 },
    { 0, 0, 18, 30, 2, 15, 0x0ad },
    { 0, 0, 14, 30, 6, 15, 0x14c }
};

const struct TextColor gUnknown_8456634 = {15, 1, 12};

const u16 gUnknown_8456638[] = INCBIN_U16("data/graphics/unknown_8456638.bin");

const u8 gUnknown_8456698[] = {17, 10, 3};

void sub_8110840(void * a0)
{
    size_t r1 = (void *)gSaveBlock1Ptr - a0;
    if (gUnknown_203AE04)
        gUnknown_203AE04 += r1;
    if (gUnknown_203ADFA != 0)
    {
        if (gUnknown_203AE08)
            gUnknown_203AE08 = (void *)gUnknown_203AE08 + r1;
        if (gUnknown_203ADFA == 2)
        {
            int r3;
            for (r3 = 0; r3 < 0x20; r3++)
                if (gUnknown_203AE0C[r3])
                    gUnknown_203AE0C[r3] += r1;
        }
    }
}

void sub_811089C(void)
{
    memset(gSaveBlock1Ptr->questLog, 0, sizeof(gSaveBlock1Ptr->questLog));
    gUnknown_203ADF8 = 0;
    gUnknown_203ADFA = 0;
    gUnknown_203AE8C = 0;
    gUnknown_203AE08 = NULL;
    gUnknown_203AE04 = 0;
    sub_8113BD8();
    sub_81138F8();
}

void sub_81108F0(u8 a0)
{
    memset(gSaveBlock1Ptr->questLog + a0, 0, sizeof(struct QuestLog));
    gUnknown_203AE04 = NULL;
}

void sub_8110920(void)
{
    gUnknown_203AE04 = NULL;
}

void sub_811092C(void)
{
    if (gUnknown_203AE8C)
        gUnknown_203AE8C();
}

bool8 sub_8110944(void * a0, size_t a1)
{
    void * r2 = gSaveBlock1Ptr->questLog[gUnknown_203ADF8].unk_568;
    void * r0 = gSaveBlock1Ptr->questLog[gUnknown_203ADF8].end;
    r0 -= a1;
    if (a0 < r2 || a0 > r0)
        return FALSE;
    return TRUE;
}

bool8 sub_8110988(void * a0, size_t a1)
{
    void * r2 = gSaveBlock1Ptr->questLog[gUnknown_203ADF8].unk_568;
    void * r0 = gSaveBlock1Ptr->questLog[gUnknown_203ADF8].end;
    r0 -= a1;
    if (a0 < r2 || a0 > r0)
        return FALSE;
    return TRUE;
}

void sub_81109CC(u8 a0)
{
    gUnknown_203ADFA = a0;
    if (a0 == 1)
        gUnknown_203AE8C = sub_8110A00;
    else
        gUnknown_203AE8C = sub_8110A3C;
}

void sub_8110A00(void)
{
    if (sub_8110E68(gUnknown_203AE98) != 1)
    {
        gUnknown_3005E88 = 0;
        sub_8110E3C();
        gUnknown_203ADFA = 0;
        gUnknown_203AE8C = NULL;
    }
}

void sub_8110A3C(void)
{
    if (gUnknown_203AE94.unk_0_0 == 2)
        gUnknown_203AE94.unk_0_0 = 0;

    if (gUnknown_203AE94.unk_0_6 == 0)
    {
        if (gUnknown_3005E88 || gUnknown_203AE94.unk_0_0 == 1 || (gUnknown_203AE94.unk_1 < 32 && gUnknown_203AE0C[gUnknown_203AE94.unk_1]))
            sub_8111AD8();
        else
        {
            gUnknown_203AE94.unk_0_6 = 2;
            ScriptContext2_Enable();
            sub_81118F4(0);
        }
    }
}

void sub_8110AB4(void)
{
    gUnknown_20370D0 = gUnknown_203ADFA;
}

u8 sub_8110AC8(void)
{
    return gSaveBlock1Ptr->questLog[gUnknown_203ADF8].unk_000;
}

void sub_8110AEC(u16 a0)
{
    if (gUnknown_203ADF8 > 3)
        gUnknown_203ADF8 = 0;

    sub_81108F0(gUnknown_203ADF8);
    sub_8113B88();
    gUnknown_203AE08 = gSaveBlock1Ptr->questLog[gUnknown_203ADF8].unk_568;
    if ((a0 >= 12 && a0 < 20) || a0 == 35)
        gSaveBlock1Ptr->questLog[gUnknown_203ADF8].unk_000 = 2;
    else
        gSaveBlock1Ptr->questLog[gUnknown_203ADF8].unk_000 = 1;
    sub_81115E8();
    sub_8110BB0(gUnknown_203ADF8);
    sub_8110BE8(gUnknown_203ADF8);
    sub_8110D94();
    sub_8110E20();
    sub_8110D48(gUnknown_203ADF8);
    gUnknown_203ADFC = 0;
    sub_8112940(2, gUnknown_203AE98, 0x100);
    sub_8110E68(gUnknown_203AE98);
    sub_81109CC(1);
}

void sub_8110BB0(u8 a0)
{
    struct QuestLog * questLog = &gSaveBlock1Ptr->questLog[a0];
    questLog->unk_001 = gSaveBlock1Ptr->location.mapGroup;
    questLog->unk_002 = gSaveBlock1Ptr->location.mapNum;
    questLog->unk_003 = gSaveBlock1Ptr->location.warpId;
    questLog->unk_004 = gSaveBlock1Ptr->pos.x;
    questLog->unk_006 = gSaveBlock1Ptr->pos.y;
}

#ifdef NONMATCHING
void sub_8110BE8(u8 a0)
{
    struct QuestLog * questLog = &gSaveBlock1Ptr->questLog[a0];
    u16 i; // r6

    sub_815A008(questLog);

    for (i = 0; i < ARRAY_COUNT(gSaveBlock1Ptr->mapObjectTemplates); i++)
    {
        if (gSaveBlock1Ptr->mapObjectTemplates[i].x < 0)
        {
            questLog->npcData[i].x = (u8)-gSaveBlock1Ptr->mapObjectTemplates[i].x;
            questLog->npcData[i].negx = TRUE;
        }
        else
        {
            questLog->npcData[i].x = (u8)gSaveBlock1Ptr->mapObjectTemplates[i].x;
            questLog->npcData[i].negx = FALSE;
        }
        if (gSaveBlock1Ptr->mapObjectTemplates[i].y < 0)
        {
            questLog->npcData[i].y = (u8)-gSaveBlock1Ptr->mapObjectTemplates[i].y;
            questLog->npcData[i].negy = TRUE;
        }
        else
        {
            questLog->npcData[i].y = (u8)gSaveBlock1Ptr->mapObjectTemplates[i].y;
            questLog->npcData[i].negy = FALSE;
        }
        questLog->npcData[i].elevation = gSaveBlock1Ptr->mapObjectTemplates[i].elevation;
        questLog->npcData[i].movementType = gSaveBlock1Ptr->mapObjectTemplates[i].movementType;
    }
}
#else
NAKED
void sub_8110BE8(u8 a0)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                "\tmov r7, r10\n"
                "\tmov r6, r9\n"
                "\tmov r5, r8\n"
                "\tpush {r5-r7}\n"
                "\tlsls r0, 24\n"
                "\tlsrs r0, 24\n"
                "\tldr r4, =gSaveBlock1Ptr\n"
                "\tmovs r1, 0xCD\n"
                "\tlsls r1, 3\n"
                "\tmuls r0, r1\n"
                "\tmovs r1, 0x98\n"
                "\tlsls r1, 5\n"
                "\tadds r0, r1\n"
                "\tldr r1, [r4]\n"
                "\tadds r7, r1, r0\n"
                "\tadds r0, r7, 0\n"
                "\tbl sub_815A008\n"
                "\tmovs r6, 0\n"
                "\tmov r9, r4\n"
                "\tmovs r2, 0x8D\n"
                "\tlsls r2, 3\n"
                "\tmov r8, r2\n"
                "\tldr r3, =0x0000046a\n"
                "\tmov r10, r3\n"
                "_08110C1C:\n"
                "\tmov r4, r9\n"
                "\tldr r1, [r4]\n"
                "\tlsls r2, r6, 1\n"
                "\tadds r0, r2, r6\n"
                "\tlsls r0, 3\n"
                "\tadds r1, r0\n"
                "\tldr r0, =0x000008e4\n"
                "\tadds r1, r0\n"
                "\tldrh r4, [r1]\n"
                "\tmovs r3, 0\n"
                "\tldrsh r0, [r1, r3]\n"
                "\tmov r12, r2\n"
                "\tcmp r0, 0\n"
                "\tbge _08110C64\n"
                "\tlsls r3, r6, 2\n"
                "\tadds r2, r7, r3\n"
                "\tnegs r0, r0\n"
                "\tmov r4, r8\n"
                "\tadds r1, r2, r4\n"
                "\tstrb r0, [r1]\n"
                "\tldr r0, =0x00000469\n"
                "\tadds r2, r0\n"
                "\tldrb r0, [r2]\n"
                "\tmovs r1, 0x1\n"
                "\torrs r0, r1\n"
                "\tstrb r0, [r2]\n"
                "\tb _08110C7C\n"
                "\t.pool\n"
                "_08110C64:\n"
                "\tlsls r3, r6, 2\n"
                "\tadds r1, r7, r3\n"
                "\tmov r2, r8\n"
                "\tadds r0, r1, r2\n"
                "\tstrb r4, [r0]\n"
                "\tldr r4, =0x00000469\n"
                "\tadds r1, r4\n"
                "\tldrb r2, [r1]\n"
                "\tmovs r0, 0x2\n"
                "\tnegs r0, r0\n"
                "\tands r0, r2\n"
                "\tstrb r0, [r1]\n"
                "_08110C7C:\n"
                "\tadds r5, r3, 0\n"
                "\tmov r1, r9\n"
                "\tldr r0, [r1]\n"
                "\tmov r2, r12\n"
                "\tadds r1, r2, r6\n"
                "\tlsls r1, 3\n"
                "\tadds r0, r1\n"
                "\tldr r3, =0x000008e6\n"
                "\tadds r1, r0, r3\n"
                "\tldrh r2, [r1]\n"
                "\tmovs r4, 0\n"
                "\tldrsh r0, [r1, r4]\n"
                "\tcmp r0, 0\n"
                "\tbge _08110CC8\n"
                "\tadds r3, r7, r5\n"
                "\tadds r1, r0, 0\n"
                "\tnegs r1, r1\n"
                "\tlsls r1, 24\n"
                "\tmov r2, r8\n"
                "\tadds r4, r3, r2\n"
                "\tlsrs r1, 15\n"
                "\tldr r0, [r4]\n"
                "\tldr r2, =0xfffe01ff\n"
                "\tands r0, r2\n"
                "\torrs r0, r1\n"
                "\tstr r0, [r4]\n"
                "\tadd r3, r10\n"
                "\tldrb r0, [r3]\n"
                "\tmovs r1, 0x2\n"
                "\torrs r0, r1\n"
                "\tb _08110CE6\n"
                "\t.pool\n"
                "_08110CC8:\n"
                "\tadds r3, r7, r5\n"
                "\tlsls r2, 24\n"
                "\tmov r0, r8\n"
                "\tadds r4, r3, r0\n"
                "\tlsrs r2, 15\n"
                "\tldr r0, [r4]\n"
                "\tldr r1, =0xfffe01ff\n"
                "\tands r0, r1\n"
                "\torrs r0, r2\n"
                "\tstr r0, [r4]\n"
                "\tadd r3, r10\n"
                "\tldrb r1, [r3]\n"
                "\tmovs r0, 0x3\n"
                "\tnegs r0, r0\n"
                "\tands r0, r1\n"
                "_08110CE6:\n"
                "\tstrb r0, [r3]\n"
                "\tadds r5, r7, r5\n"
                "\tmov r1, r9\n"
                "\tldr r0, [r1]\n"
                "\tmov r2, r12\n"
                "\tadds r3, r2, r6\n"
                "\tlsls r3, 3\n"
                "\tadds r0, r3\n"
                "\tldr r4, =0x000008e8\n"
                "\tadds r0, r4\n"
                "\tldrb r1, [r0]\n"
                "\tmov r0, r10\n"
                "\tadds r4, r5, r0\n"
                "\tlsls r1, 2\n"
                "\tldrb r2, [r4]\n"
                "\tmovs r0, 0x3\n"
                "\tands r0, r2\n"
                "\torrs r0, r1\n"
                "\tstrb r0, [r4]\n"
                "\tmov r1, r9\n"
                "\tldr r0, [r1]\n"
                "\tadds r0, r3\n"
                "\tldr r2, =0x000008e9\n"
                "\tadds r0, r2\n"
                "\tldrb r0, [r0]\n"
                "\tldr r3, =0x0000046b\n"
                "\tadds r5, r3\n"
                "\tstrb r0, [r5]\n"
                "\tadds r0, r6, 0x1\n"
                "\tlsls r0, 16\n"
                "\tlsrs r6, r0, 16\n"
                "\tcmp r6, 0x3F\n"
                "\tbhi _08110D2A\n"
                "\tb _08110C1C\n"
                "_08110D2A:\n"
                "\tpop {r3-r5}\n"
                "\tmov r8, r3\n"
                "\tmov r9, r4\n"
                "\tmov r10, r5\n"
                "\tpop {r4-r7}\n"
                "\tpop {r0}\n"
                "\tbx r0\n"
                "\t.pool");
}
#endif // NONMATCHING

void sub_8110D48(u8 a0)
{
    struct QuestLog * questLog = &gSaveBlock1Ptr->questLog[a0];

    CpuCopy16(gSaveBlock1Ptr->flags, questLog->unk_148, FLAGS_COUNT * sizeof(u8));
    CpuCopy16(gSaveBlock1Ptr->vars, questLog->unk_268, VARS_COUNT * sizeof(u16));
}

void sub_8110D94(void)
{
    u16 i, j;
    u16 sp0[4];

    for (i = 0; i < 4; i++)
    {
        sp0[i] = 0;
        for (j = 0; j < 16; j++)
        {
            if (gSaveBlock1Ptr->trainerRematches[16 * i + j])
            {
                sp0[i] += (1 << j);
            }
        }
        VarSet(VAR_0x40AA + i, sp0[i]);
    }
}

void sub_8110E20(void)
{
    VarSet(VAR_0x40AE, gSaveBlock1Ptr->mapDataId);
}

void sub_8110E3C(void)
{
    sub_8113BF4(gUnknown_203AE08);
    if (++gUnknown_203ADF8 > 3)
        gUnknown_203ADF8 = 0;
}

bool8 sub_8110E68(struct UnkStruct_203AE98 * a0)
{
    u16 i;

    for (i = gUnknown_203ADFC; i < gUnknown_203AF98; i++)
    {
        if (gUnknown_203AE08 == NULL)
            return FALSE;
        switch (a0[i].unk_6)
        {
            case 0:
            case 1:
                gUnknown_203AE08 = sub_8113D48(gUnknown_203AE08, &a0[i]);
                break;
            default:
                gUnknown_203AE08 = sub_8113CC8(gUnknown_203AE08, &a0[i]);
                break;
        }
        if (gUnknown_203AE08 == NULL)
        {
            gUnknown_3005E88 = 0;
            return FALSE;
        }
    }

    if (gUnknown_3005E88 == 0)
    {
        gUnknown_203AE08 = sub_8113BF4(gUnknown_203AE08);
        return FALSE;
    }
    gUnknown_203ADFC = gUnknown_203AF98;
    return TRUE;
}

void sub_8110F14(u8 taskId)
{
    u8 i;

    sub_811381C();
    gUnknown_203ADF9 = 0;
    for (i = 0; i < 4; i++)
    {
        if (gSaveBlock1Ptr->questLog[i].unk_000)
            gUnknown_203ADF9++;
    }

    if (gUnknown_203ADF9 != 0)
    {
        gUnknown_3005ECC = FALSE;
        sub_8110F90(taskId);
        DestroyTask(taskId);
    }
    else
    {
        SetMainCallback2(sub_8056938);
        DestroyTask(taskId);
    }
}

void sub_8110F90(u8 unused)
{
    gSaveBlock1Ptr->location.mapGroup = 3;
    gSaveBlock1Ptr->location.mapNum = 19;
    gSaveBlock1Ptr->location.warpId = -1;
    gUnknown_203ADF8 = 0;
    gUnknown_2031DD8 = 1;
    sub_8082740(1);
    sub_8111368();
}

void sub_8110FCC(void)
{
    sub_811175C(gUnknown_203ADF8, gUnknown_203AE98);
    sub_8113B88();
    sub_8112940(1, gUnknown_203AE98, 0x100);
    sub_8111150(gUnknown_203ADF8);
}

bool8 sub_8111000(void)
{
    LoadPalette(stdpal_get(4), 0xF0, 0x20);
    sub_81109CC(2);
    sub_807DF64();
    gUnknown_203AE94 = (struct UnkStruct_203AE94){};
    gUnknown_203AE94.unk_0_0 = 2;
    return 1;
}

bool8 sub_8111038(void)
{
    LoadPalette(stdpal_get(4), 0xF0, 0x20);
    sub_81109CC(2);
    sub_807DF7C();
    gUnknown_203AE94 = (struct UnkStruct_203AE94){};
    gUnknown_203AE94.unk_0_0 = 2;
    return 1;
}

void sub_8111070(u8 a0)
{
    u8 i;

    for (i = 0; i < 3; i++)
    {
        gUnknown_203ADFE[i] = AddWindow(&gUnknown_845661C[i]);
        FillWindowPixelRect(gUnknown_203ADFE[i], 15, 0, 0, gUnknown_845661C[i].width * 8, gUnknown_845661C[i].height * 8);
    }

    // _("Previously on your quest…$")
    StringExpandPlaceholders(gStringVar4, gUnknown_841A155);

    if (a0)
    {
        ConvertIntToDecimalStringN(gStringVar1, a0, STR_CONV_MODE_LEFT_ALIGN, 1);
        StringAppend(gStringVar4, gStringVar1);
    }

    AddTextPrinterParametrized2(gUnknown_203ADFE[0], 2, 2, 2, 1, 2, &gUnknown_8456634, 0, gStringVar4);
    PutWindowTilemap(gUnknown_203ADFE[0]);
    PutWindowTilemap(gUnknown_203ADFE[1]);
    CopyWindowToVram(gUnknown_203ADFE[0], 2);
    CopyWindowToVram(gUnknown_203ADFE[2], 2);
    CopyWindowToVram(gUnknown_203ADFE[1], 3);
}

void sub_8111134(void)
{
    PutWindowTilemap(gUnknown_203ADFE[1]);
    CopyWindowToVram(gUnknown_203ADFE[1], 1);
}

void sub_8111150(u8 a0)
{
    struct QuestLog *questLog = &gSaveBlock1Ptr->questLog[a0];
    u16 i;
    
    for (i = 0; i < 64; i++)
    {
        if (questLog->npcData[i].negx)
            gSaveBlock1Ptr->mapObjectTemplates[i].x = -questLog->npcData[i].x;
        else
            gSaveBlock1Ptr->mapObjectTemplates[i].x = questLog->npcData[i].x;
        if (questLog->npcData[i].negy)
            gSaveBlock1Ptr->mapObjectTemplates[i].y = -(u8)questLog->npcData[i].y;
        else
            gSaveBlock1Ptr->mapObjectTemplates[i].y = questLog->npcData[i].y;
        gSaveBlock1Ptr->mapObjectTemplates[i].elevation = questLog->npcData[i].elevation;
        gSaveBlock1Ptr->mapObjectTemplates[i].movementType = questLog->npcData[i].movementType;
    }

    sub_815A1F8(questLog, gSaveBlock1Ptr->mapObjectTemplates);
}

void sub_8111274(u8 a0, u8 a1)
{
    struct WarpData sp0;
    
    if (!a1)
    {
        gSaveBlock1Ptr->location.mapGroup = gSaveBlock1Ptr->questLog[a0].unk_001;
        gSaveBlock1Ptr->location.mapNum = gSaveBlock1Ptr->questLog[a0].unk_002;
        gSaveBlock1Ptr->location.warpId = gSaveBlock1Ptr->questLog[a0].unk_003;
        gSaveBlock1Ptr->pos.x = gSaveBlock1Ptr->questLog[a0].unk_004;
        gSaveBlock1Ptr->pos.y = gSaveBlock1Ptr->questLog[a0].unk_006;
    }
    else
    {
        sp0.mapGroup = gSaveBlock1Ptr->questLog[a0].unk_001;
        sp0.mapNum = gSaveBlock1Ptr->questLog[a0].unk_002;
        sp0.warpId = gSaveBlock1Ptr->questLog[a0].unk_003;
        sp0.x = gSaveBlock1Ptr->questLog[a0].unk_004;
        sp0.y = gSaveBlock1Ptr->questLog[a0].unk_006;
        sub_8055D5C(&sp0);
    }
}

void sub_8111368(void)
{
    gUnknown_203ADFA = 2;
    sub_806E6FC();
    sub_809A2DC();
    sub_809A2A4();
    if (sub_8110AC8() == 1)
    {
        sub_8111274(gUnknown_203ADF8, 0);
        gUnknown_3005024 = sub_8111038;
        SetMainCallback2(sub_80572A8);
    }
    else
    {
        sub_8111274(gUnknown_203ADF8, 1);
        warp_in();
        gUnknown_3005024 = sub_8111000;
        SetMainCallback2(sub_805726C);
    }
}

void sub_81113E4(void)
{
    struct QuestLog * questLog = &gSaveBlock1Ptr->questLog[gUnknown_203ADF8];

    CpuCopy16(questLog->unk_148, gSaveBlock1Ptr->flags, FLAGS_COUNT * sizeof(u8));
    CpuCopy16(questLog->unk_268, gSaveBlock1Ptr->vars, VARS_COUNT * sizeof(u16));
    sub_8111688();
}

struct PokemonAndSomethingElse
{
    struct Pokemon mon;
    u16 unk_64;
    u16 unk_66;
};

void sub_8111438(void)
{
    struct PokemonAndSomethingElse *r9 = AllocZeroed(sizeof(struct PokemonAndSomethingElse));
    u16 r0, r3, r5, r6;

    CreateMon(&r9->mon, SPECIES_RATTATA, 1, 0x20, FALSE, 0, 0, 0);
    r0 = VarGet(VAR_0x4027);
    r9->unk_64 = r0 >> 12;
    r9->unk_66 = r0 % 0x1000;

    r5 = sub_8111618();
    if (r5 > r9->unk_64)
    {
        for (r3 = 0; r3 < r5 - r9->unk_64; r3++)
        {
            ZeroMonData(&gPlayerParty[5 - r3]);
        }
    }
    else if (r5 < r9->unk_64)
    {
        for (r3 = 0; r3 < 5; r3++)
        {
            sub_808BCB4(0, r3);
        }
        for (r3 = r5; r3 < r9->unk_64; r3++)
        {
            CopyMon(&gPlayerParty[r3], &r9->mon, sizeof(struct Pokemon));
        }
    }

    r5 = sub_811164C();
    if (r5 > r9->unk_66)
    {
        for (r3 = 0; r3 < 14; r3++)
        {
            for (r6 = 0; r6 < 30; r6++)
            {
                if (GetBoxMonDataFromAnyBox(r3, r6, MON_DATA_SANITY_BIT2))
                {
                    sub_808BCB4(r3, r6);
                    r5--;
                    if (r5 == r9->unk_66)
                        break;
                }
            }
            if (r5 == r9->unk_66)
                break;
        }
    }
    else if (r5 < r9->unk_66)
    {
        for (r3 = 0; r3 < TOTAL_BOXES_COUNT; r3++)
        {
            for (r6 = 0; r6 < IN_BOX_COUNT; r6++)
            {
                struct BoxPokemon * boxMon = GetBoxedMonPtr(r3, r6);
                if (!GetBoxMonData(boxMon, MON_DATA_SANITY_BIT2))
                {
                    CopyMon(boxMon, &r9->mon.box, sizeof(struct BoxPokemon));
                    r5++;
                    if (r5 == r9->unk_66)
                        break;
                }
            }
            if (r5 == r9->unk_66)
                break;
        }
    }

    Free(r9);
}

void sub_81115E8(void)
{
    u16 r4 = sub_8111618();
    u16 r1 = sub_811164C();
    VarSet(VAR_0x4027, (r4 << 12) + r1);
}

u16 sub_8111618(void)
{
    u16 count = 0;
    u16 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SANITY_BIT2))
            count++;
    }

    return count;
}

u16 sub_811164C(void)
{
    u16 count = 0;
    u16 i, j;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (GetBoxMonDataFromAnyBox(i, j, MON_DATA_SANITY_BIT2))
                count++;
        }
    }

    return count;
}

void sub_8111688(void)
{
    u16 i, j;
    u16 sp0[4];

    for (i = 0; i < 4; i++)
    {
        sp0[i] = VarGet(VAR_0x40AA + i);

        for (j = 0; j < 16; j++)
        {
            if (sp0[i] & 1)
                gSaveBlock1Ptr->trainerRematches[16 * i + j] = 30;
            else
                gSaveBlock1Ptr->trainerRematches[16 * i + j] = 0;
            sp0[i] >>= 1;
        }
    }
}

void sub_8111708(void)
{
    struct MapHeader sp0;

    gSaveBlock1Ptr->mapDataId = VarGet(VAR_0x40AE);
    if (gSaveBlock1Ptr->mapDataId == 0)
    {
        sp0 = *get_mapheader_by_bank_and_number(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
        gSaveBlock1Ptr->mapDataId = sp0.mapDataId;
    }
}

void sub_811175C(u8 a0, struct UnkStruct_203AE98 * a1)
{
    u16 i;
    u16 *r4;
    u16 r6 = 0;
    u16 r9 = 0;

    memset(a1, 0, 32 * sizeof(struct UnkStruct_203AE98));
    for (i = 0; i < 32; i++)
    {
        gUnknown_203AE0C[i] = NULL;
    }

    r4 = gSaveBlock1Ptr->questLog[a0].unk_568;
    for (i = 0; i < 32; i++)
    {
        switch (*r4 & 0xFFF)
        {
            case 0:
                r4 = sub_8113D08(r4, &a1[r6]);
                r6++;
                break;
            case 1:
            case 2:
                r4 = sub_8113D94(r4, &a1[r6]);
                r6++;
                break;
            case 39:
                r4 = sub_8113C20(r4, &a1[r6]);
                r6++;
                break;
            case 41:
                r4 = sub_8113C8C(r4, &a1[r6]);
                r6++;
                break;
            default:
                r4 = sub_8113A78(r4, &gUnknown_203AE0C[r9]);
                if (r9 == 0)
                    sub_8113ABC(gUnknown_203AE0C[0]);
                r9++;
                break;
        }
        if (r4 == NULL)
            break;
    }
}

void sub_81118F4(s8 a0)
{
    fade_screen(1, a0);
    gUnknown_203AE8C = sub_8111914;
}

void sub_8111914(void)
{
    if (!gPaletteFade.active)
    {
        ScriptContext2_Enable();
        if (++gUnknown_203ADF8 < 4 && gSaveBlock1Ptr->questLog[gUnknown_203ADF8].unk_000)
        {
            gUnknown_203ADF9--;
            sub_8111368();
        }
        else
        {
            gUnknown_3005E88 = 0;
            sub_8111984();
        }
    }
}

void sub_8111984(void)
{
    sub_806E6FC();
    ResetSaveCounters();
    sub_80DA4FC(0);
    SetMainCallback2(sub_8057430);
    gUnknown_3005024 = sub_8111F60;
    FreeAllWindowBuffers();
    gUnknown_203ADFA = 3;
    gUnknown_203AE8C = NULL;
}

void sub_81119C8(void)
{
    sub_8111914();
}

bool8 sub_81119D4(void (*a0)(void))
{
    u8 taskId;

    switch (gUnknown_203ADFA)
    {
        case 1:
            sub_8112364();
            break;
        case 2:
            gUnknown_3005E88 = 3;
            taskId = CreateTask(sub_8111A34, 80);
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].data[1] = 0;
            SetWordTaskArg(taskId, 14, (u32)a0);
            return TRUE;
    }
    return FALSE;
}

void sub_8111A34(u8 taskId)
{
    void (*routine)(void);
    s16 * data = gTasks[taskId].data;

    switch (data[1])
    {
        case 0:
            if (++data[0] == 0x7F)
            {
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
                gUnknown_203AE94.unk_0_6 = 2;
                data[1]++;
            }
            break;
        case 1:
            if (!gPaletteFade.active)
            {
                gUnknown_3005E88 = 0;
                routine = (void (*)(void)) GetWordTaskArg(taskId, 14);
                if (routine != NULL)
                    routine();
                DestroyTask(taskId);
                gUnknown_203AE8C = sub_8111914;
            }
            break;
    }
}

void sub_8111AD8(void)
{
    if (gUnknown_203AE94.unk_0_0 == 1)
    {
        if (--gUnknown_203AE94.unk_2 != 0)
            return;
        gUnknown_203AE94.unk_0_0 = 0;
        gUnknown_203AE94.unk_0_4 = 1;
        sub_8112888(2);
    }

    if (gUnknown_203AE94.unk_0_4 == 1)
    {
        if (++gUnknown_203AE94.unk_3 > 15)
        {
            sub_8111E20();
            gUnknown_203AE94.unk_0_4 = 0;
            gUnknown_203AE94.unk_3 = 0;
        }
    }
    if (gUnknown_203AE94.unk_1 < 32)
    {
        if (sub_8113B44(gUnknown_203AE0C[gUnknown_203AE94.unk_1]) == 1)
            sub_8111B80();
        else if (sub_8113AE8(gUnknown_203AE0C[gUnknown_203AE94.unk_1]) == 1)
            sub_8111B80();
    }
}

void sub_8111B80(void)
{
    if (gUnknown_203AE94.unk_0_0 == 0)
    {
        gUnknown_203AE94.unk_0_0 = 1;
        gUnknown_203AE94.unk_0_4 = 0;
        gUnknown_203AE94.unk_3 = 0;
        gUnknown_203AE94.unk_2 = sub_8111BD4();
        if (gUnknown_203B044[1] == 0)
            gUnknown_203AE94.unk_1++;
        if (gUnknown_203AE94.unk_1 > 32)
            return;
        sub_8111D10();
    }
    sub_8112888(1);
}

u8 sub_8111BD4(void)
{
    u16 i;
    u16 count = 0;

    for (i = 0; i < 0x400 && gStringVar4[i] != EOS; i++)
    {
        if (gStringVar4[i] != CHAR_NEWLINE)
            count++;
    }

    if (count < 20)
        return 0x5F;
    if (count < 36)
        return 0x7F;
    if (count < 46)
        return 0xBF;
    return 0xFF;
}

bool8 sub_8111C2C(void)
{
    if (gUnknown_203ADFA != 2)
        return FALSE;
    if (gUnknown_3005E88 == 0 || gUnknown_203AE94.unk_0_0 == 1 || gUnknown_203AE94.unk_0_0 == 2)
        return TRUE;
    return FALSE;
}

void sub_8111C68(void)
{
    if (gUnknown_203AE94.unk_0_6 == 0)
    {
        if (gMain.newKeys & A_BUTTON)
        {
            gUnknown_203AE94.unk_0_6 = 2;
            gUnknown_3005E88 = 0;
            sub_81118F4(-3);
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            gUnknown_203AE94.unk_0_6 = 1;
            gUnknown_3005E88 = 0;
            sub_8111E64(-3);
        }
    }
}

bool8 sub_8111CD0(void)
{
    if (gUnknown_203AE94.unk_0_6 != 0)
        return TRUE;
    return FALSE;
}

void sub_8111CF0(void)
{
    if (gUnknown_203ADFA == 2)
        sub_8111070(gUnknown_203ADF9);
}

void sub_8111D10(void)
{
    u16 i;
    u8 count = 0;

    for (i = 0; i < 0x100 && gStringVar4[i] != EOS; i++)
    {
        if (gStringVar4[i] == CHAR_NEWLINE)
            count++;
    }

    PutWindowTilemap(gUnknown_203ADFE[2]);
    sub_8111D90(gUnknown_203ADFE[2]);
    AddTextPrinterParametrized2(gUnknown_203ADFE[2], 2, 2, gUnknown_8456698[count], 1, 0, &gUnknown_8456634, 0, gStringVar4);
    schedule_bg_copy_tilemap_to_vram(0);
}

void sub_8111D90(u8 a0)
{
    const u16 * src = gUnknown_8456638;
    u16 * buffer = Alloc(0x1680);
    u8 i, j, y;

    if (buffer)
    {
        for (i = 0; i < 6; i++)
        {
            switch (i)
            {
                default:
                    y = 1;
                    break;
                case 0:
                    y = 0;
                    break;
                case 5:
                    y = 2;
                    break;
            }

            // r6 = y * 32
            // r5 = 2 * (i % 16)
            // r4 = j
            for (j = 0; j < 30; j++)
            {
                CpuCopy32(src + 16 * y, buffer + 16 * (2 * (15 * i) + j), 32);
            }
        }

        CopyToWindowPixelBuffer(a0, (const u8 *)buffer, 0x1680, 0);
        Free(buffer);
    }
}

void sub_8111E20(void)
{
    ClearWindowTilemap(gUnknown_203ADFE[2]);
    FillWindowPixelRect(gUnknown_203ADFE[2], 15, 0, 0, 0xf0, 0x30);
    CopyWindowToVram(gUnknown_203ADFE[2], 2);
    PutWindowTilemap(gUnknown_203ADFE[1]);
    CopyWindowToVram(gUnknown_203ADFE[1], 1);
}

void sub_8111E64(s8 a0)
{
    fade_screen(1, a0);
    gUnknown_203AE8C = sub_8111E84;
}

void sub_8111E84(void)
{
    if (!gPaletteFade.active)
    {
        ScriptContext2_Enable();
        for (gUnknown_203ADF8 = gUnknown_203ADF8; gUnknown_203ADF8 < 4; gUnknown_203ADF8++)
        {
            if (gSaveBlock1Ptr->questLog[gUnknown_203ADF8].unk_000 == 0)
                break;
            sub_811175C(gUnknown_203ADF8, gUnknown_203AE98);
        }
        gUnknown_3005E88 = 0;
        sub_8111984();
    }
}

void sub_8111F14(void)
{
    if (gUnknown_203ADFA == 3)
        gUnknown_203AE90 = AllocZeroed(0x200 * sizeof(u16));
}

void sub_8111F38(u16 a0, u16 a1)
{
    CpuSet(gUnknown_20371F8 + a0, gUnknown_203AE90 + a0, a1);
}

bool8 sub_8111F60(void)
{
    LoadPalette(stdpal_get(4), 0xF0, 0x20);
    sub_8111070(0);
    sub_807DF7C();
    CreateTask(sub_8111F8C, 0xFF);
    return TRUE;
}

void sub_8111F8C(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (ScriptContext2_IsEnabled() != TRUE)
    {
        player_bitmagic();
        sub_805C270();
        sub_805C780();
        ScriptContext2_Enable();
        task->func = sub_8111FCC;
    }
}
