inherit ROOM;
void create()
{
          set("short","住宅區入口");
          set("long",@LONG
這裡就是採礦區旁的住宅區，住在這的多是礦工和他們的家人。但由
於礦工在這年代被列為厭惡性行業，所以這裡均為低密度住宅。這裡來往
礦工非常方便，使礦工每天的工作時間較久。
LONG
          );
          set("world", "future");
        set("outdoors","desert");
          set("exits", ([ /* sizeof() == 2 */
	  "south" : __DIR__"digging_street4",
          ]));
          set("item_desc",([
               "石刻":
"一塊巨型的石刻，上面刻著：「這裡只開放給已登記居民。」\n",
]) );
          set("no_clean_up", 0);
          setup();
          replace_program(ROOM);
}
