inherit ROOM;

void create()
{
        set("short", "�H�ۤl��");
        set("long", @LONG
�o�̬O�䳣 �ɦw�������~���D���A���W�Q���۸H�ۤl�A���n���h�i�H��
    �춯�����ִ������s�A�_��i�H�ݨ���R���վB�����C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"room45",
  "southeast" : __DIR__"room47",
  //"north" : __DIR__"room34",
  //"east" : __DIR__"room45",
])); 
        set("light",1);

        setup();
        //replace_program(ROOM);
}
