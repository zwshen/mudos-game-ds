#include <ansi.h>
inherit ROOM;

void create()
{
  set( "short", "地底神殿遺跡") ;
  set( "long",NOR""
"寬廣的大廳中，擺\著十幾尊不同的雕像，每座雕像都刻得栩栩如\n"
"生，怒目圓睜地瞪著來往的人們，大廳的正中央有一尊特別巨大的雷\n"
"神雕像，"HIC"右手握劍平舉"NOR"，"HIC"左手指著地下"NOR"，不知道有什麼特殊涵意。\n"NOR
);
  set("exits", ([ /* sizeof() == 4 */
"northeast" : __DIR__"room-18",
"northwest" : __DIR__"room-16",
"southeast" : __DIR__"room-14",
"southwest" : __DIR__"room-12",
]));
  set("light",0);
  set( "item_desc", ([ /* sizeof() == 1 */
"雕像" : "雷神的雕像，其腰間有一顆黃色的寶石，握劍的那隻手似乎可以轉動其方向(turning)。\n",
]) );
  set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
  set("no_clean_up", 0);
  setup();
}

void init()
{
  add_action("thunder_god","turning");
}

int thunder_god(string str)
{
  if (this_object()->query_temp("opened") != 0) return 0;

  if (str=="up" || str=="sky" )
  {
    say(HIY+"雷神像的右手被轉向指著天空，形成天地獨尊之勢...\n"+NOR);
    say(HIY+"雷神像緩緩開口道：「"+HIW+"右手指天，左手指地，天上地下，唯我獨尊！"+HIY+"狂雷開路！！」\n"+NOR);
    say(HIW+"雷神像腰間的寶石放出強大的電擊，一時之間電光充斥四周，讓你睜不開眼！！\n"+NOR);
    write(HIY+"你將雷神像的右手轉成指向天空，形成天地獨尊之勢...\n"+NOR);
    write(HIY+"雷神像緩緩開口道：「"+HIW+"右手指天，左手指地，天上地下，唯我獨尊！"+HIY+"狂雷開路！！」\n"+NOR);
    write(HIY+"雷神像腰間的寶石放出強大的電擊，將你衝向了正前方的牆壁！！\n"+NOR);
    write(HIR+"在雷電的衝擊中，你撞塌了牆壁，出現一條通路，但全身疼痛不堪...\n"+NOR);

    this_player()->receive_damage("hp",100+random(50));

    set( "exits", ([
"northwest" : __DIR__"room-16",
"northeast" : __DIR__"room-18",
"southwest" : __DIR__"room-12",
"southeast" : __DIR__"room-14",    
"north" : __DIR__"room-17",
]) );

    set( "item_desc", ([
    "雕像" : "雷神的雕像，其腰間有一顆黃色的寶石，握劍的手已經卡死轉不動了。\n",
            ]) ); 

    set( "long", @EndText
寬廣的大廳中，擺著十幾尊不同的雕像，每座雕像都刻得栩栩如
生，怒目圓睜地瞪著來往的人們，大廳的正中央有一尊特別巨大的雷
神雕像，右手握劍指天，左手指著地下，一副唯我獨尊的架勢。
EndText
  );

    set_temp("opened",1);
    return 1;
  }
  write("你在亂轉個什麼勁啊？\n");
  return 1;
}

void reset()
{
  set( "long",NOR""
"寬廣的大廳中，擺\著十幾尊不同的雕像，每座雕像都刻得栩栩如\n"
"生，怒目圓睜地瞪著來往的人們，大廳的正中央有一尊特別巨大的雷\n"
"神雕像，"HIC"右手握劍平舉"NOR"，"HIC"左手指著地下"NOR"，不知道有什麼特殊涵意。\n"NOR
);

  set("exits", ([ /* sizeof() == 4 */
"northeast" : __DIR__"room-18",
"northwest" : __DIR__"room-16",
"southeast" : __DIR__"room-14",
"southwest" : __DIR__"room-12",
]));

  set( "item_desc", ([ /* sizeof() == 1 */
"雕像" : "雷神的雕像，其腰間有一顆黃色的寶石，握劍的那隻手似乎可以轉動其方向(turning)。\n",
]) );
  delete_temp("opened");
  ::reset();
}

