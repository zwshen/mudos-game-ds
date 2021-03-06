//
// Cosplay Show     Wilfred@DS  2000/12/25
//

#include <ansi2.h>
inherit NPC;

int obj_clone(string t, string l, int index);
string do_color(string arg);

mapping color = ([
"$HBWHT$" : HBWHT,
"$BBLK$"  : NOR+BBLK,
"$HBRED$" : HBRED,
"$BRED$"  : NOR+BRED,
"$HBGRN$" : HBGRN,
"$BGRN$"  : NOR+BGRN,
"$HBYEL$" : HBYEL,
"$BYEL$"  : NOR+BYEL,
"$HBBLU$" : HBBLU,
"$BBLU$"  : NOR+BBLU,
"$HBMAG$" : HBMAG,
"$BMAG$"  : NOR+BMAG,
"$HBCYN$" : HBCYN,
"$BCYN$"  : NOR+BCYN,
"$BLK$" : HIW+BLK,
"$WHT$" : NOR+WHT,
"$HIW$" : HIW,
"$RED$" : RED,
"$HIR$" : HIR,
"$GRN$" : GRN,
"$HIG$" : HIG,
"$YEL$" : YEL,
"$HIY$" : HIY,
"$BLU$" : BLU,
"$HIB$" : HIB,
"$MAG$" : MAG,
"$HIM$" : HIM,
"$CYN$" : CYN,
"$HIC$" : HIC,
"$NOR$" : NOR
]);

void create()
{
  set_name("工作人員", ({"man"}) );
set("title",HIW"聖誕節 "HIG"C"HIW"os"HIG"p"HIW"lay "HIW"Show"NOR);
  set("race","human");
  set("age",25);
  set("level",1);
  set("gender", "男性");

  set("long",@LONG
他是 cosplay 活動的工作人員, 你可以輸入 m_apply
申請變裝用的 EQ 或 WP.
LONG
);
  set("chat_chance",10);
  set("chat_msg",({
(: command("say 聖誕 Cosplay Show (CP)己經開始, 您可以 look man 查詢使用方法喔!") :),
(: command("smile") :),
(: command("say 請遵守會場秩序, 謝謝您的合作.") :),
(: command("sweat") :),
}) );

  set("no_kill",1);
  set("no_fight",1);
  set("no_cast",1);
  set("no_exert",1);
setup();
}

void init()
{
  add_action("do_apply","m_apply");
  add_action("do_help","help");
}

int do_apply(string str)
{
  string t, l;
  object obj;

  if(!str) return notify_fail("不知道格式請 help m_apply\n");
  if( sscanf(str,"%s %s",t,l) != 2 ) notify_fail("不知道格式請 help m_apply\n");

  message_vision(HIC"\n$N給$n一張 cosplay show 的申請表。\n\n"NOR,this_player(),this_object());

  if( t != "id_card" )
  {
    if(!obj_clone(t,l,1))
      if(!obj_clone(t,l,2))
{
//      command("say 對不起, 好像沒有這種類型的 EQ 或 WP 喔...");
        command("say 對不起, 好像沒有這種類型的 EQ 喔...");
        return 1;
      }
  }
  else
  {
    obj = new("/std/armor/neck.c");
    obj->set_name("識別證" ,({ "id_card" }) );
    obj->set_weight(1);
    obj->set("armor_prop/name", ({do_color(l)}) );
    obj->set("armor_type","neck");
    obj->set("limit_con",2);
    obj->set("armor_prop/armor",1);
    obj->setup();
    obj->move(this_player());
  }

  command("smile");
  command("say 這是您要的東西, 祝您玩得愉快!");

  return 1;
}

int obj_clone(string t, string l, int index)
{
  string error, bak = t;
  object obj, me = this_player();
  mapping attack;

  if(index == 1) t = "/std/armor/"+t+".c";
  if(index == 2) t = "/std/weapon/"+t+".c";
  if(index == 2)
  {
    command("say 抱歉, 目前 WP 不開放申請 ^.^");
    return 0;
  }

  if( file_size(t) < 0 ) return 0;
  if( !find_object(t) )
  {
    error = catch(call_other(t, "???"));
    if (error) return 0;
  }
  error = catch(obj = new(t));
if (error) return 0;
  if( !obj->move(me) )
  {
    destruct(obj);
    return 0;
  }

  obj->set_name(do_color(l),({bak}));
  obj->set_weight(1);
  obj->setup();
  if(index == 1)
  {
    obj->set("armor_type",bak);
    obj->set("limit_con",2);
    obj->set("armor_prop/armor",1);
  }

  // WP 的部分有問題, 再作研究

  if(index == 2)
  {
    obj->set("skill_type",bak);
    obj->set("verbs", ({ "hit" }) );
obj->set("actions", (: call_other, WEAPON_D, "query_action" :) );
    obj->set("material","unknow");
    obj->set("weapon_prop/damage",1);
    obj->set("flag",4);
    obj->set("limit_str",2);
  }

  return 1;
}

string do_color(string arg)
{
  object me = this_player(), ob = this_object();
  int i;
  string temp = arg;
  string *source_color;
  string *target_color;

  if(!arg) arg = "某物";
  source_color = keys(color);
  target_color = values(color);

  for(i=0;i<sizeof(source_color);i++)
temp = replace_string(temp, source_color[i], "");

  if( strlen(temp) > 20 )
  {
    write("System message: 最多只能使用 20 個半形文字，過多則造成亂碼，而色碼的使用則不在此限。\n");
    return "亂碼";
  }

  for(i=0;i<sizeof(source_color);i++)
    arg = replace_string(arg, source_color[i], target_color[i]);

  arg += NOR;

  return arg;
}

int do_help(string str)
{
  string msg;
  if(str != "m_apply") return 0;

  write(@HELP

●申請 cosplay 道具表●
  指令格式: m_apply [裝備種類] [名稱]

  裝備種類: WP 類 - 拳 fist      EQ 類 - 盾 shield
                    劍 sword             盔 head
                    刀 blade             面 mask
                    矛 fork              頸 neck(另見: 識別證 id_card)
                    匕 dagger            衣 cloth
                    鎚 hammer            甲 armor
                    斧 axe               肩 surcoat
                    鞭 whip              腕 wrists
                    弓 bow               掌 hands
                    棍 staff             指 finger
                    槍 gun               腰 waist
                                         褲 pants
                                         脛 legging
                                         鞋 boots

  識別證 id_card: 屬於 neck 類, 設定其名稱用來改變個人稱號

  名稱: 請勿超過 20 個半形字, 上色方法請參照 help nick

HELP
);
 
  return 1;
}


