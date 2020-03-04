inherit ROOM;
void create()
{
	set("short", "步靈城西大街");
	set("long",@LONG
這是一條大街的起頭，似乎很漫長的樣子，但走起來卻不會如你想
像中的長，這條街是由土加石頭所組成，所以你走路是會感覺腳底會有
一點痛，而當有馬車經過時就會有輪子卡到石頭的聲音出現，東邊是往
廣場，而西邊則是往西大門。
LONG
	);
	set("exits", ([
  "east" : __DIR__"bwest1.c",
  "west" : __DIR__"bwest3.c",
]));

	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
