inherit ROOM;

void create()
{
  set("short", "�n���O��");
  set("long", @LONG
��ߦb��f�n�誺�O��A�Υ۶����Ӧ��A�����Q�X�X�A�]�ߩ�
�ѭԤ��ήɷ|�U�N���ﰵ����J�䪺���ޡA���n���h�i�H�ݨ컷
�����·¶���ִ������s�C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "northeast" : __DIR__"room16",
     ]));
  set("outdoors","land");
  setup();
}
