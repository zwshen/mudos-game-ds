// shijie9.c �۶�
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�۶�");
        set("long", @LONG
�o�O�@��������۪O���A�̤s�ӫءA�H�ۤs�ժ�����d�馱��C
�ѩ�s�հ~�F�A����׫سo���۶��ɪ֩w�O�F���p���\�ҡC����o
�̡A�w�g�i�H�ݨ����u�Э����[���Ѩ��F�C�譱�n�����@���p���C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "south"     : __DIR__"guanritai",
                "northdown" : __DIR__"shijie8",
        ]));
        set("objects",([
                __DIR__"npc/daotong" : 2,
        ]));

	set("coor/x", -3150);
	set("coor/y", 90);
	set("coor/z", 180);
	setup();
        replace_program(ROOM);
}