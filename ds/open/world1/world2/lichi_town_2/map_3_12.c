inherit ROOM;
void create()
{
	set("short", "ªZ¾¹©±ÂdÂi");
        set("long", @LONG

  ¢y¡Ä          ¢z¢w¢w¢w¢w¢w¢w¢{            ¡Ä¢j
  ¢¬¢¨¢j        ¢x  ªZ    ¾¹  ¢x          ¢y¢©¢­
¢¬¢¬¢¨¢j      ¡Ä¢|¢w¢w O¢w¢w¢w¢}¡Ä        ¢y¢©¢­¢­
¢i¢¬¢¨¢j      ¢©¢­    /Y\     ¢¬¢¨        ¢y¢©¢­¢i
¢i¢¬¢¨¢j      ¢i¢©¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¢¨¢i        ¢y¢©¢­¢i
¢i¢¬¢¬¡Ã¡Ã¡Ã¡Ã¢ª¢i¢i¢i¢i¢i¢i¢i¢i¢«¡Ã¡Ã¡Ã¡Ã¡Ã¢­¢­¢i
¢i¢¬            ¢ª¢i¢i¢i¢i¢i¢i¢«              ¢­¢i
¡Ã                                              ¡Ã
LONG
);
	set("exits",([
	"east" : __DIR__"map_3_13",
	"south" : __DIR__"map_4_12",
	"north" : __DIR__"map_2_12",
	]));
	set("objects",([
	__DIR__"../npc/malo_wpboss_18" : 1,
	]));
	set("light",1);
        setup();
}
/*
string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}

*/