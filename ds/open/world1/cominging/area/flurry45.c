inherit MOBROOM;
void create()
{
	set("short", "�m�Z��");
	set("long", @LONG
�o�̬O�e�������m�Z���A�o���T���s�j�A�@����h�A�ɬO�m�Z���A
�m�Z���W���\�h���e�����̤l�b�m�Z�Ϊ̽m���\�A���Φb��s�ۦ��A��
���]�]�t�F�L���̤l�ӽбСA�����F�Z�\���j���h�A�m�Z�����䳣���@
���\�ۼC���[�l�A�W����۳\�h�_�����a�����C���Z���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"flurry44.c",
  "south" : __DIR__"flurry40.c",
]));
	set("no_clean_up", 0);
	set("chance",40);
	set("mob_amount", 2);
	set("mob_object",({
  __DIR__"npc/apprentice",
}));
	set("outdoors","land");
	setup();
}