inherit ROOM;

void create()
{
  set("short", "果菜大市場");
  set("long", @LONG
這裡是港都賽安尼爾斯中的果菜、魚肉買賣大市場，港都與鄰近
城鎮的食物交易都在這個市場進行，你看到市場中攤位眾多，有各式
各樣的蔬菜、水果、魚肉等，到處是攤販叫賣聲，非常地熱鬧吵雜。
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room27",
      "northeast" : __DIR__"room53",
     ])); 
  set("light",1);
  setup();
}
