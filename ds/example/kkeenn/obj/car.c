// 有取到作者同意copy    by lestia

// by snowcat 5/3/1997
#include <ansi.h>

inherit ITEM;

mapping chinese_dirs = ([
  "north":        "北",
  "south":        "南",
  "east":         "東",
  "west":         "西",
  "northup":      "北邊",
  "southup":      "南邊",
  "eastup":       "東邊",  
  "westup":       "西邊",
  "northdown":    "北邊",
  "southdown":    "南邊",
  "eastdown":     "東邊",
  "westdown":     "西邊",
  "northeast":    "東北",
  "northwest":    "西北",
  "southeast":    "東南",
  "southwest":    "西南",
  ]);

mapping left_dirs = ([
  "north":        "northwest",
  "south":        "southeast",
  "east":         "northeast",
  "west":         "southwest",
  "northeast":    "north",
  "northwest":    "west",
  "southeast":    "east",
  "southwest":    "south",
  ]);

mapping right_dirs = ([
  "north":        "northeast",
  "south":        "southwest",
  "east":         "southeast",
  "west":         "northwest",
  "northeast":    "east",
  "northwest":    "north",
  "southeast":    "south",
  "southwest":    "west",
  ]);

string *makes = ({
  "Acura NXL",
  "Audi Cabriolet",
  "BMW 850",
  "Buick Skylark",
  "Cadillac Seville",
  "Chevrolet Monte Carlo",
  "Chrysler Sebring Convertable",
  "Dodge Viper",
  "Eagle Vision",
  "Ford Thunderbird",
  "Geo Metro",
  "Honda Accord",
  "Hyundai Sonata",
  "Infinti Q45",
  "Jaguar",
  "Lexus SC400",
  "Lincoln Towncar",
  "Mazda Protege",
  "Mercedes-Benz SLK-CLASS",
  "Mercury Tracer",
  "Mitsubishi Mirage",
  "Nissan Maxima",
  "Oldsmobile Aurora",
  "Plymouth Neon",
  "Pontiac Sunfire",
  "Porsche Boxster",
  "Saab 9000",
  "Saturn",
  "Subaru Legacy",
  "Suzuki Esteem",
  "Toyota Camry",
  "Volksvagon Passat",
  "Volvo 960",
  });

void create()
{
  string name = makes[random(sizeof(makes))]+" 轎車";

  set_name(name, ({"car", "che"}));
  set_weight(300000);
  set_max_encumbrance (1000000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("short", name+"(Car)");
    set("long", "這是一輛"+name+"。\n");
    set("unit", "輛");
    set("material", "metal");
    set("value", 1000000);
    set("dir", "north");
    set("speed", 0);
    set("fuel", 10000);
    set("miles", 0);
  }
  setup();
}

void automate();

int init()
{
  add_action("do_enter", "enter");
  add_action("do_out", "out");
  add_action("do_look", "look");
  add_action("do_left", "4");
  add_action("do_right", "6");
  add_action("do_speedup", "8");
  add_action("do_slowdown", "2");
  add_action("do_stop", "5");
  add_action("do_handdrive", "7");
  add_action("do_autodrive", "9");
  automate();
  return 1;
}

int test_busy ()
{
  object me = this_object();
  object who = this_player();

  if (me->query_temp("is_busy"))
  {
    tell_object (who,"動作別太猛，車子會搞壞的！\n");    
    return 1;
  }
  me->set_temp("is_busy",1);
  remove_call_out ("reset_busy_temp");
  call_out ("reset_busy_temp",1,me);
  return 0;

}

void reset_busy_temp (object me)
{
  me->set_temp("is_busy",0);  
}

int is_in ()
{
  object me = this_object();
  object who = this_player();
  return environment(who) == me; 
}

int is_driver ()
{
  object me = this_object();
  object who = this_player();

  if (me->query("driver") != who)
  {
    tell_object (who,"別亂動，你又不是司機！\n");  
    return 0;
  }
  return 1;
}

int report_outside_objects ()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);
  mixed *inv = all_inventory(where);
  int i;

  if (sizeof(inv) <= 1)
    return 1;

  tell_object (who,"外面有：");  
  for (i=0; i < sizeof(inv); i++)
  {
    if (inv[i] != me)
      tell_object (who,inv[i]->query("name")+"("+inv[i]->query("id")+") ");    
  }
  tell_object (who,"\n");  
  return 1;
}

int report_inside_objects ()
{
  object me = this_object();
  object who = this_player();
  mixed *inv = all_inventory(me);
  int i;

  if (sizeof(inv) == 0)
    return 1;

  tell_object (who,"車裡有：");  
  for (i=0; i < sizeof(inv); i++)
  {
    tell_object (who,inv[i]->query("name")+"("+inv[i]->query("id")+") ");    
  }
  tell_object (who,"\n");  
  return 1;
}

int report_dir ()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);
  mapping exits = where->query("exits");
  string *dirs;
  int i;

  if (! exits)
    return 1;

  dirs = keys(exits);

  tell_object (who,"四面的出口是：");  
  for (i=0; i < sizeof(dirs); i++)
  {
    tell_object (who,chinese_dirs[dirs[i]]+"("+dirs[i]+")");    
  }
  tell_object (who," [車頭朝向："+chinese_dirs[me->query("dir")]+
                   "("+me->query("dir")+")]\n");  
  return 1;
}

int report_view ()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);

  tell_object (who,"≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n");  
  tell_object (who,"從車窗裡可以看到：");  
  tell_object (who,where->query("short")+"\n");  
  tell_object (who,where->query("long")+"\n");  
  report_outside_objects();
  report_dir();
  tell_object (who,"≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n");  
  return 1;
}

int report_short ()
{
  object me = this_object();
  object who = this_player();
  string strspeed, strfuel, strmiles;
  int i, len = 15;

  strspeed = "速度："+sprintf("%d",me->query("speed"));
  strfuel  = "汽油："+sprintf("%d",me->query("fuel")) ;
  strmiles = "里程："+sprintf("%d",me->query("miles"));
  for (i = sizeof(strspeed); i < len; i++)
    strspeed = strspeed + " ";
  for (i = sizeof(strfuel); i < len; i++)
    strfuel = strfuel + " ";
  for (i = sizeof(strmiles); i < len; i++)
    strmiles = strmiles + " ";
  tell_object (who,"\n");  
  tell_object (who,"  □□□□□□□□□□□□□□□□□□□□□□\n");  
  tell_object (who,"  □"+ strspeed + " 7[手導] 8[加速] 9[自導] □\n");  
  tell_object (who,"  □"+ strfuel  + " 4[左轉] 5[剎車] 6[右轉] □\n");  
  tell_object (who,"  □"+ strmiles + "         2[減速]         □\n");  
  tell_object (who,"  □□□□□□□□□□□□□□□□□□□□□□\n");  
  if (me->query("autodrive") > 0)
    tell_object (who,"  方向控制：全自動");  
  else
    tell_object (who,"  方向控制：手動");  
  if (me->query("driver"))
    tell_object (who,"  司機："+me->query("driver")->query("name"));  
  tell_object (who,"\n");  
  report_inside_objects();
  return 1;
}

int do_enter (string arg)
{
  object me = this_object();
  object who = this_player();

  if (arg != "car")
    return 0;

  if (is_in())
    return 0;

  if (me->query("speed") > 0)
  {
    tell_object (who,"跳進正在行駛的車子會有生命危險！\n");  
    return 1;
  }

  message_vision ("$N一彎腰，坐進車。\n",who);
  who->move(me);
  if (! me->query("driver") ||
      environment(me->query("driver")) != me)
  {
    me->set("driver",who);
    message_vision ("$N坐在司機座位上。\n",who);
  }
  else
    message_vision ("$N坐在客座上。\n",who);
  return 1;
}

int do_out (string arg)
{
  object me = this_object();
  object who = this_player();

  if (! is_in())
    return 0;

  if (me->query("speed") > 0)
  {
    tell_object (who,"跳出正在行駛的車子會有生命危險！\n");  
    return 1;
  }

  if (me->query("driver") == who)
  {
    me->set("driver",0);
  }

  message_vision ("$N一打開車門跳下車。\n",who);
  who->move(environment(me));
  message_vision ("$N跳出車，將車門關上。\n",who);
  return 1;
}

int do_look (string arg)
{
  object me = this_object();
  object who = this_player();

  if (! is_in())
  {
    if (arg == "car")
    {
      tell_object (who,"這是一"+me->query("unit")+me->query("name")+
                   "(enter)。\n");
      return 1;
    }
    return 0;
  }
  report_view();
  report_short();
  return 1;
}

int do_left (string arg)
{
  object me = this_object();
  object who = this_player();
  string dir = me->query("dir");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  if (me->query("speed") == 0)
  {
    tell_object (who,"先將車子發動起來再轉彎。\n");
    return 1;  
  }

  dir = left_dirs[dir];
  tell_object (who,"你將方向盤向左一轉。\n");  
  message_vision (me->query("name")+"車頭朝"+chinese_dirs[dir]+
                  "一拐……\n",me);
  me->set("dir",dir);
  return 1;
}

int do_right (string arg)
{
  object me = this_object();
  object who = this_player();
  string dir = me->query("dir");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  if (me->query("speed") == 0)
  {
    tell_object (who,"先將車子發動起來再轉彎。\n");
    return 1;  
  }

  dir = right_dirs[dir];
  tell_object (who,"你將方向盤向右一轉。\n");  
  message_vision (me->query("name")+"車頭朝"+chinese_dirs[dir]+
                  "一拐……\n",me);
  me->set("dir",dir);
  return 1;
}

int do_speedup (string arg)
{
  object me = this_object();
  object who = this_player();
  int s = me->query("speed");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  if (s == 0)
  {
    s += 2+random(4);
    tell_object (who,"你點火發動車子。\n");  
    message_vision (me->query("name")+"輕吼了一聲，排氣管吐出一股青煙\n",me);
  }
  else if (s < 45)
  {
    s += 4+random(8);
    tell_object (who,"你踩了一踩油門。\n");  
    message_vision (me->query("name")+"輕輕地加速。\n",me);
  }
  else if (s < 90)
  {
    s += 8+random(16);
    tell_object (who,"你用力踩了一踩油門。\n");  
    message_vision (me->query("name")+"嗖地一聲加快了時速！\n",me);
  }
  else 
  {
    s += 16+random(32);
    tell_object (who,"你使勁地了踩了一踩油門。\n");  
    message_vision (me->query("name")+"發瘋似地加速！\n",me);
  }
  if (s > 320)
    s = 320;
  me->set("speed",s);
  return 1;
}

int do_slowdown (string arg)
{
  object me = this_object();
  object who = this_player();
  int s = me->query("speed");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  if (s == 0)
  {
    tell_object (who,"車子已經停了。\n");  
  }
  else if (s < 45)
  {
    s -= 4+random(8);
    tell_object (who,"你輕輕地踩了踩閘。\n");  
    message_vision (me->query("name")+"慢慢減速。\n",me);
  }
  else if (s < 90)
  {
    s -= 8+random(16);
    tell_object (who,"你踩了踩閘。\n");  
    message_vision (me->query("name")+"明顯地慢了下來。\n",me);
  }
  else 
  {
    s -= 16+random(32);
    tell_object (who,"你使勁地踩了一踩閘。\n");  
    message_vision (me->query("name")+"在飛弛中減速。\n",me);
  }
  if (s < 0)
    s = 0;
  me->set("speed",s);
  return 1;
}

int do_stop (string arg)
{
  object me = this_object();
  object who = this_player();
  int s = me->query("speed");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  if (s == 0)
  {
    tell_object (who,"車子已經停了。\n");  
  }
  else if (s < 20)
  {
    s = 0;
    tell_object (who,"你猛地一剎車。\n");  
    message_vision (me->query("name")+"輕輕一顛，停了。\n",me);
  }
  else if (s < 45)
  {
    s = 0;
    tell_object (who,"你一個急剎車！\n");  
    message_vision (me->query("name")+"突然急劇地減速！\n",me);
    message_vision (me->query("name")+"發出一聲長長的尖叫，吱一聲停了！\n",me);
    tell_object (who,"你猛地蹌了一下！\n");  
  }
  else if (s < 100)
  {
    s -= 40+random(40);
    tell_object (who,"你瘋狂地踩閘急剎車！\n");  
    message_vision (me->query("name")+"突然急劇地減速！\n",me);
    message_vision (me->query("name")+"劇烈地震動著！\n",me);
    tell_object (who,"你一陣頭暈，差一點吐了出來！\n");  
  }
  else 
  {
    s -= 60+random(60);
    tell_object (who,"你不顧一切地地踩閘急剎車！\n");  
    message_vision (me->query("name")+"突然急劇地減速！\n",me);
    message_vision (me->query("name")+"可怕地震動著，地上划出兩道黑印！\n",me);
    tell_object (who,"強烈的震動中你一陣劇烈頭痛！\n");  
    //who->unconcious();
  }
  if (s < 0)
    s = 0;
  me->set("speed",s);
  return 1;
}

int do_handdrive (string arg)
{
  object me = this_object();
  object who = this_player();
  int s = me->query("speed");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  me->set("autodrive",0);
  tell_object (who,"現在手動控制行車方向。\n");  
  return 1;
}

int do_autodrive (string arg)
{
  object me = this_object();
  object who = this_player();
  int s = me->query("speed");

  if (! is_in())
    return 0;

  if (! is_driver())
    return 1;

  if (test_busy())
    return 1;

  me->set("autodrive",1);
  tell_object (who,"現在全自動控制行車方向。\n");  
  return 1;
}

void collision ()
{
  object me = this_object();
  object who = me->query("driver");
  int s = me->query("speed");
  string *hits = ({
    "衝出了路",
    "滑進路邊的草叢中",
    "撞進一個大土堆",
    "滑進一灘爛泥",
    "闖進一個小木棚",
    "衝向一大叢灌木叢",
    "撞向一片小樹",
  });
  string how;

  if (s == 0)
    how = "極輕地";
  else if (s < 20)
    how = "當一聲";
  else if (s < 40)
    how = "嘩啦一聲";
  else if (s < 60)
    how = "砰地一聲";
  else if (s < 80)
    how = "轟地一聲";
  else if (s < 100)
    how = "像脫韁野馬一樣地";
  else if (s < 150)
    how = "極瘋狂地";
  else 
    how = "天塌地裂般地";

  if (s < 50)
  {
    message_vision (me->query("name")+how+hits[random(sizeof(hits))]+
                    "。\n",me);
    message_vision (me->query("name")+"停了下來。\n",me);
  }
  else if (s < 100)
  {
    message_vision (me->query("name")+how+hits[random(sizeof(hits))]+
                    "！\n",me);
    message_vision (me->query("name")+"在一陣強烈的震動中停了下來！\n",me);
    tell_object (who,"你一陣目眩！\n");  
  }
  else
  {
    message_vision (me->query("name")+how+hits[random(sizeof(hits))]+
                    "！\n",me);
    message_vision (me->query("name")+"在一陣極可怕的震動中發出巨響！\n",me);
    message_vision ("一切又突然安靜了下來停了下來。\n",me);
    tell_object (who,"你一剎那覺得窗外的所有東西向你猛地扑來又突然停止！\n");  
    //who->unconcious();
  }
  me->set("speed",0);
}

void display_me ()
{
  object me = this_object();
  string name = me->query("name");
  int s = me->query("speed");
  string msg = 0;

  if (s == 0)
  {
    set("short", "停在路上的"+name+"(Car)");    
  }
  else if (s < 30)
  {
    set("short", "慢慢行駛的"+name+"(Car)");
    msg = name+"慢慢地駛著。\n";
  }
  else if (s < 50)
  {
    set("short", "行駛中的"+name+"(Car)");
    msg = name+"正在行駛著。\n";
  }
  else if (s < 110)
  {
    set("short", "飛駛的"+name+"(Car)");
    msg = name+"飛快地行駛著。\n";
  }
  else 
  {
    set("short", "狂駛中的"+name+"(Car)");
    msg = name+"發瘋似地狂駛著。\n";
  }
  if (msg && 
      random(10) == 0)
    message_vision (msg,me);
}

void check_speed ()
{
  object me = this_object();

  if (me->query("speed") > 0 &&
      me->query("fuel") <= 0)
  {
    me->set("speed",0);
    message_vision
(me->query("name")+"奇怪地冒出一股青煙，沒有汽油了。\n",me);
    message_vision (me->query("name")+"有氣無力地停了。\n",me);
  }

  if (me->query("speed") > 0 &&
      (! me->query("driver") ||
        environment(me->query("driver")) != me))
  {
    me->set("speed",0);
    message_vision (me->query("name")+"沒有司機了。\n",me);
    message_vision (me->query("name")+"吱地一聲歪歪斜斜地停了。\n",me);
  }
}

void check_fuel ()
{
  object me = this_object();

  if (me->query("speed") > 0 &&
      me->query("fuel") > 0)
  {
    int f = me->query("fuel");

    f -= (me->query("speed")/10+1); 
    if (f < 0)
      f = 0;
    me->set("fuel",f);
  }
}

void check_miles ()
{
  object me = this_object();

  if (me->query("speed") > 0)
  {
    me->add("miles",me->query("speed")/6);
  }
}

object find_room (string dest)
{
  object me = this_object();
  object where = environment(me);

  if (!dest)
    return 0;
  return find_object(dest);
}

object find_exit ()
{
  object me = this_object();
  object where = environment(me);
  object who = me->query("driver");
  string dir = me->query("dir");
  object obj = 0;
  mapping dirs;
  string dest;

  if (!mapp(dirs = where->query("exits")))
  {
 tell_object (who,"這裡好象沒有什麼路可走了。\n");
    return 0;  
  }

while (obj == 0)
  {
    dest = dirs[dir];
    if (dest)
      obj = find_room(dest);
    if (!dest || !obj)
    {
      dest = dirs[dir+"down"];
      if (dest)
        obj = find_room(dest);
    }
    if (!dest || !obj)
    {
      dest = dirs[dir+"up"];
      if (dest)
        obj = find_room(dest);
    }
    if (!dest || !obj)
    {
      if (me->query("autodrive"))
      {
        if (random(2) == 0)
          dir = left_dirs[dir];
        else
          dir = right_dirs[dir];
        continue;
      }
      else
      {
        if (random(3) == 0)
          tell_object (who,"前方("+chinese_dirs[dir]+
  ")沒有什麼路可行了。\n");
        return 0;
      }  
    }

    if (! obj->query("outdoors"))
    {
      if (me->query("autodrive"))
      {
        if (random(2) == 0)
          dir = left_dirs[dir];
        else
          dir = right_dirs[dir];
        continue;
      }
      else
      {
        if (random(3) == 0)
          tell_object (who,"前方("+chinese_dirs[dir]+
                           ")不是汽車可行的路。\n");
        return 0;
      }  
    }
    
    if (me->query("car_from/"+where->query("short"))==obj->query("short") &&
        me->query("autodrive") &&
        random(20))
      obj = 0;
  }
  if (me->query("autodrive"))
  {
    if (random(3) == 0)
      tell_object (who,"汽車現在向"+chinese_dirs[dir]+"行駛。\n");
    me->set("dir",dir);
  }
  return obj;
}

void check_move ()
{
  object me = this_object();
  object where = environment(me);
  object exit = 0;

  if (me->query("speed") == 0)
    return;

  exit = find_exit();
  me->add("distance",me->query("speed")/5+1);
  if (me->query("distance") < 100)
    return;

  me->set("distance",0);
  if (! exit)
  {
    remove_call_out("collision");
    call_out ("collision",1);
  }
  else
  {
    me->set("car_from/"+exit->query("short"),where->query("short"));
    message_vision (me->query("name")+"開出"+where->query("short")+"。\n",me);
    me->move(exit);
    message_vision (me->query("name")+"開進"+exit->query("short")+"。\n",me);
  }
}

void automate ()
{
  check_speed ();
  check_fuel ();
  check_miles (); 
  display_me ();
  remove_call_out("check_move");
  call_out("check_move",2); 
  remove_call_out("automate");
  call_out("automate",5);
}

