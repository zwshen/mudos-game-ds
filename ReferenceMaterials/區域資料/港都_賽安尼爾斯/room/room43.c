inherit ROOM;

void create()
{
  set("short", "�ө�����\\�]");
  set("long", @LONG
�٨S����o�̴N�w�g�D�쭻���F�A�o�̬O���ܼ��x���\�]�A�b��
�i�H�ɨ�������ˡB�����i�f�������A�ר�]���F�����A�o�̪���
�A�Ʋz�i�H���O�s�A�S�K�y��C
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room42",
      "northeast" : __DIR__"room40",
      "east" : __DIR__"room44",
     ])); 
  set("light",1);
  setup();
}
