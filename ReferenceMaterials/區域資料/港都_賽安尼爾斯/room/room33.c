inherit ROOM;

void create()
{
  set("short", "���x�����Фj��");
  set("long", @LONG
�o�̬O���x�������j���f�A�����䪺���ɵP�l�W��ۮ��üаO�H
��"�ۢϢ�עܢ�"�A��Ǧ����x����L���b����A���̭��ݹL�h�i�H
�ݨ�զ⪺�ؿv���μe�諸�޳��C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room32",
      "south" : __DIR__"room36",
      "north" : __DIR__"room30",
      "east" : __DIR__"room34",
     ])); 
  set("light",1);
  setup();
}
