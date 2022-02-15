inherit ROOM;

void create()
{
  set("short", "商店街－餐\館");
  set("long", @LONG
還沒走到這裡就已經聞到香味了，這裡是間很熱鬧的餐館，在此
可以享受到熱騰騰、美味可口的食物，尤其因為鄰近海港，這裡的海
鮮料理可以說是新鮮又便宜喔。
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
