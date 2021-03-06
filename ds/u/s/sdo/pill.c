// 不打算給 ppl 支援背景色了... 再說吧  wilfred@DS
// 如果要支援背景色要包含 ansi2.h 才能使用

#include <ansi2.h>
inherit ITEM;

mapping color = ([
/*
// ---- 背景色 -----
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
*/
// ---- 前景色 -----
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

int do_color(string arg, int index);
int do_try(string arg);

void create()
{
  set_name(HIB"易丹"NOR, ({ "pill" }));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
    set("long","\n這是一顆神秘的藥丸，是瀧走在路上撿到的。\n"
    	       "使用方法請輸入『help pill』。\n");
  setup();
}
int valid_user(object me)
{
        if(!wizardp(me))
                return notify_fail("只有巫師才能用。\n");
        return 1;
}
void init()
{
  add_action("do_change","change");
  add_action("do_help","help");
}

int do_change(string mess)
{
  if(!mess) return notify_fail("你想改變啥阿？\n");
  if((mess!="min")&&(mess!="mout")&&(mess!="home")&&(mess!="rank")&&(mess!="clone")&&(mess!="dest"))
	return notify_fail("沒這種啦...-.-凸。\n");
  this_player()->set_temp("wants",mess);
  write("你現在想要改變的是"+this_player()->query_temp("wants")+"。\n"
        "請用color更改，用try嘗試。\n");
  add_action("do_try","try");
  add_action("do_color","color");
  return 1;
}
  
int do_try(string arg)
{
  if(!arg) return notify_fail("請輸入您想要的文字.\n");
  do_color(arg,1);
  return 1;
}
int do_color(string arg, int index)
{
  object me = this_player(), ob = this_object();
  int i;
  string temp = arg;
  string *source_color;
  string *target_color;

  if(!arg) return notify_fail("請輸入您想要的文字.\n");
  source_color = keys(color);
  target_color = values(color);

  for(i=0;i<sizeof(source_color);i++)
    temp = replace_string(temp, source_color[i], "");

/*  if( strlen(temp) > 16 )
  {
    write("System message: 最多只能使用 16 個半形文字，顏色的使用則不在此限。\n若你設定的文字不足 16 個半形，則系統自動補足空白至 16 個。\n");
    return 1;
  }
  else
  {
    for(i=0;i<( 16 - strlen(temp) );i++)
      arg += " ";
  }
*/
  for(i=0;i<sizeof(source_color);i++)
    arg = replace_string(arg, source_color[i], target_color[i]);

  if(!index)
  {
    if(me->query_temp("wants") == "rank")
      me->set("guild_rank",arg + NOR);
    if(me->query_temp("wants") == "min")
      me->set("env/msg_min",arg + NOR);
    if(me->query_temp("wants") == "mout")
      me->set("env/msg_mout",arg + NOR);
    if(me->query_temp("wants") == "home")
      me->set("msg_home",arg + NOR);
    if(me->query_temp("wants") == "clone")
      me->set("env/msg_clone",arg + NOR);
    if(me->query_temp("wants") == "dest")
      me->set("env/msg_dest",arg + NOR);
    
    message_vision(HIW"\n$N吃下一顆$n"HIW"，看起來好像很滿足的樣子。\n\n"NOR,me,ob);
    me->save();
    destruct(ob);
  }
  else write(NOR"測試結果: 你的" +me->query_temp("wants")+ "將會改成 『" +arg+ NOR"』 。\n");
  return 1;
}

int do_help(string str)
{
  if(!str || str != "pill") return 0;
  write("\n一個聲音悠悠說道：\n"
  	"這個藥丸可以更改你的 "HIG"Guild-Rank 名稱及顏色。\n"NOR
  	"                     "HIG"msg_min，msg_mout的字串也可以。\n"NOR
  	"                     "HIG"msg_home，msg_clone，msg_dest當然不例外。\n"NOR
  	"，上色方法請 help nick。\n\n"
  	HIC"◎用法: change message◎\n"NOR
  	HIC"◎message可用rank,min,mout,home,clone,dest◎\n"NOR);
  return 1;
}
