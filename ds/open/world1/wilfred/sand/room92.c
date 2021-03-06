// 開戰 & 戰爭結束的 room , 結束時伏義石陣會震出許多金礦來  wilfred@DS

#include <ansi.h>

int is_war();
void start_war();
void end_war(int j);
void armageddon(int index_t);
string get_item();

inherit ROOM;
void create()
{
  set ("short", "左磐龍殿");
  set ("long", @LONG
這裡是正殿的旁枝，在當時也就是所謂的偏殿，這裡有面牆是為
黃色沙金鑲框的，上頭掛了許多木板片，寫著一些易經中之文字，整
面牆分為四大部分，看來似乎是為了區分這些木板片的內容。
LONG
);
  set("exits", ([
  "east" : __DIR__"room90",
]));
  set("item_desc", ([
  "木板片" : (: get_item :),
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
}

int is_war()
{
  return query("is_war");
}

void start_war()
{
  set("is_war",1);
  call_out("clone_mob",5);
  return;
}

void clone_mob()
{
  /*
     ●定義在迴圈裡的●
     機關木龍   x 5
     機關鐵龍   x 4
     機關銀龍   x 3
     機關金龍   x 2
     翼守龍     x 1
     千年龍     x 1
     鑽石龍     x 1

     ●位置一定的●
     真紅眼黑龍 x 1 把關小頭目
     青眼白龍   x 1 把關老大
     -------------------------
                 19 隻
  */

  string *npc = ({
"37","37","37","37","37",
"38","38","38","38",
"39","39","39",
"40","40",
"41","42","43"
});

  int i, index;

  message("world:world1:vision",
  HIC"\n\t前古的封印又再度被喚醒了......一道青白相間的龍氣從磐龍山巔爆震開來！！\n"+
  HIR"\n\t\t磐龍山群龍盡出，血光震天！！\n\n"NOR,users() );

  for(i=0;i<sizeof(npc);i++)
  {
    index = (random(11)+78);
    if(index == 83 || index == 87) index++;
    new(__DIR__"npc/npc"+npc[i])->move(__DIR__"room"+(string)index);
    tell_room(__DIR__"room"+(string)index,"一團黑影突然出現在你面前。\n");
  }
  new(__DIR__"npc/npc44")->move(__DIR__"room89");
  new(__DIR__"npc/npc45")->move(__DIR__"room90");


  call_out("end_war",2000+random(600));
  return;
}

void end_war(int j)
{
  object mob, room, *env;
  int i, index;

  if(!j)
  {
    if( objectp(mob = find_living("dragon_war")) )
    {
      tell_room(environment(mob), HIW"\n天上忽然降下一道強光包圍了"+mob->name(1)+" .....\n\n"NOR);
      destruct(mob);
      call_out("end_war",3);
    }
    else
    {
      delete("is_war");
      room = load_object(__DIR__"room49");
      room->reset();
      room = load_object(__DIR__"room88");
      room->reset();

      for(index=78;index<93;index++)
      {
        room = find_object(__DIR__"room"+(string)index);
        if(!room) continue;
        env = all_inventory(room);
        if(!env) continue;
        for(i=0;i<sizeof(env);i++)
          if(userp(env[i]) || env[i]->query("id") == "tent")
          {
            tell_object(env[i],HIW"\n你忽然被一陣強光包圍 ..... 你只覺得一陣暈眩 ..\n\n"NOR);
            env[i]->move(__DIR__"room49");
          }
          else destruct(env[i]);
      }
      message("world:world1:vision",
      HIW"\n\t血光散去，群龍回歸，磐龍山回歸平靜。\n\n"NOR,users() );
    }
    return;
  }
  else
  {
    call_out("armageddon",5,200);
    call_out("gold_mine",1);
  }
  return;
}

void armageddon(int index_t)
{
  object room;
  int index;

  if(index_t < 3)
  {
    remove_call_out("armageddon");
    call_out("go_die",1);
    return;
  }

  if(index_t < 17)
  {
    index_t -= 3;
    for(index=46;index<93;index++)
    {
      room = load_object(__DIR__"room"+(string)index);
      if(!room) continue;
      tell_room(room,"還有 "+index_t+" 秒整個磐龍山就要毀滅了，請盡速離開。\n");
    }
    call_out("armageddon",3,index_t);
  }
  else
  {
    index_t -= 15;
    for(index=46;index<93;index++)
    {
      room = load_object(__DIR__"room"+(string)index);
      if(!room) continue;
      tell_room(room,"還有 "+index_t+" 秒整個磐龍山就要毀滅了，請盡速離開。\n");
    }
    call_out("armageddon",15,index_t);
  }
  return;
}

void gold_mine()
{
  object room;
  int index;

  index = random(24) + 50;
  room = load_object(__DIR__"room"+(string)index);
  if( room )  {
          tell_room(room, HIY"\n鏗！！一塊金礦從岩壁震了出來！\n"NOR);
        new(__DIR__"npc/obj/obj30")->move(room);
  }
  call_out("gold_mine", 6+random(4) );
}

void go_die()
{
  object room, *env;
  int index, i;
  string msg = "";

  room = load_object(__DIR__"room46");
  room->armageddon();
  room = load_object(__DIR__"room49");
  room->reset();
  room = load_object(__DIR__"room88");
  room->reset();

  remove_call_out("gold_mine");
  for(index=46;index<93;index++)
  {
    room = load_object(__DIR__"room"+(string)index);
    if(!room) continue;
    env = all_inventory(room);
    if(!env) continue;
    for(i=0;i<sizeof(env);i++)
      if(userp(env[i]))
      {
        tell_object(env[i],HIW"\n你瞬間慘遭白光吞噬，你死前所能看到的，只剩毀滅....\n\t眼前的黑不是黑，眼前的白是什麼白...\n\n"NOR);
        msg +=  env[i]->name(1);
        env[i]->set_temp("last_damage_from", new(__DIR__"npc/hill.c") );
        env[i]->die();

      }
      else destruct(env[i]);
  }
  message("world:world1:vision",
  HIW"\n\t磐龍山被天上降下的巨型白色光束擊中，一陣天搖地動，磐龍山頓時灰飛煙滅 ..... \n\n"  NOR,users() );
  if(msg != "")
          message("world:world1:vision",
                  HIG"  " + msg + " 等人不幸罹難在磐龍山中，令天下人惋惜。\n"NOR, users() );
  delete("is_war");
  delete("get_item");
  return;
}

string get_item()
{
  if(query("get_item")) return "一些木板片，上面寫了一些文字。\n";
  message_vision("\n$N在木板片裡發現了一個靈位！！\n\n",this_player());
  new(__DIR__"npc/obj/obj21")->move(environment(this_player()));
  set("get_item",1);
  return "";
}

void reset()
{
  if(is_war()) return;
    else ::reset();
}

