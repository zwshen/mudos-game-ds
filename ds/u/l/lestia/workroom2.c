//by lestia
inherit "/u/l/lestia/work/inroom.c";
#include <ansi.h>

string *trust = ({});
string *exclude = ({});

mixed query_trust() {return trust;}
mixed query_exclude() {return exclude;}

void create()
{
restore_object(__DIR__"data.o");
        set("short", HIW""BLK"邪闇"HIW"之間"NOR);
  set("long",
"\n你站在一片虛無的大地之中，灰暗的天緩緩的流動著，\n"
"你眼觀四周，發現這裡除了沉寂之外還是沉寂，你沉默\n"
"不語，慢慢的將心中的雜念去除，只留下邪惡的念頭，\n"
"等待著最後之日的降臨。\n\n"
);
set("light", 1);
        set("no_clean_up", 0);
 set("valid_startroom", 1); 
 set("exits", ([ 
"wiz":"/d/wiz/hall1",
"up":"/u/l/lestia/work/post.c",
"pray":"/u/l/lestia/work/pray.c",
"luky":"/u/l/luky/workroom.c",
 ])); 
        setup();
 call_other("/obj/board/lestia_b", "???");
}

void heart_beat()
{
        object ob, who;

        if(!find_player(geteuid())) {
                set_heart_beat(0);
                return;
        }
        if(ob = query_snoop(find_player(geteuid()))) {
                snoop(ob);
                who = find_player(geteuid());
                if(geteuid(who) == geteuid())
                tell_object(who , HIW"Warning: "+capitalize(geteuid(ob))+" is Snoop you!\n"NOR);
        }
}

void init()
{
 if(geteuid(this_player()) == "lestia") {
  add_action("do_editrank","editrank");
        add_action("do_show","show");
         add_action("do_clo","clo");
        add_action("do_add_trust","add_trust");
        add_action("do_del_trust","del_trust");
        add_action("do_add_exclude","add_exclude");
        add_action("do_del_exclude","del_exclude");
    }
    ::init();
}
int do_editrank(string arg)
{
int i;
string str;
object me;
me = this_player();
 if(!arg) return notify_fail("你要將你的Rank改成什麼？\n");;
me->set("nickname",HIY"記憶裡"NOR""YEL"那片刻"HIY"的華美"NOR""YEL"，不曾"HIY"褪色，"NOR""YEL"卻化為"HIY"永恆。"NOR);
me->set("guild_rank",HIC"風"NOR""CYN"雲"HIC"天"NOR""CYN"下"HIC"隨"NOR""CYN"舞"HIC"化"NOR""CYN"盡"NOR);
tell_object(me,"成功\\n\n");
return 1;
}
int do_clo(string arg)
{
int i;
string str;
object me;
me = this_player();
if(!arg) return notify_fail("你要變什麼？\n");;
arg->move(me);
tell_object(me,"ok\\n\n");
return 1;
}

static int do_show(string arg)
{
     int i;
     string msg;

     msg = "Trust :\n";
     for(i=0;i<sizeof(trust);i++) {
           msg += trust[i] + ", ";
     }
     msg += "\nExclude :\n";
     for(i=0;i<sizeof(exclude);i++) {
           msg += exclude[i] + ", ";
     }
     msg += "\n";
     this_player()->start_more(msg);
     return 1;
}

static int do_add_trust(string arg)
{
     if(!arg) return 0;
     if(member_array(arg, trust) != -1) return notify_fail(arg+"已經在名單中了。\n");
     trust += ({ arg });
save_object(__DIR__"data.o");
     return 1;
}

static int do_del_trust(string arg)
{
     if(!arg) return 0;
     if(member_array(arg, trust) == -1) return notify_fail(arg+"已經不在名單中了。\n");
     trust -= ({ arg });
   save_object(__DIR__"data.o");
     return 1;
}

static int do_add_exclude(string arg)
{
     if(!arg) return 0;
     if(member_array(arg, exclude) != -1) return notify_fail(arg+"已經在名單中了。\n");
     exclude += ({ arg });
   save_object(__DIR__"data.o");
     return 1;
}

static int do_del_exclude(string arg)
{
     if(!arg) return 0;
     if(member_array(arg, exclude) != -1) return notify_fail(arg+"已經在名單中了。\n");
     exclude -= ({ arg });
   save_object(__DIR__"data.o");
     return 1;
}

