//飛船 構想來源:UW未知世界 , 加強版 By Dontpkme
// alickyuen@ds fix bug :p
#include <ansi.h>

inherit ROOM;

void welcome(object ob);

mapping default_dirs = ([
        "north":                "北",
        "south":                "南",
        "east":                 "東",
        "west":                 "西",
        "northup":              "北邊",
        "southup":              "南邊",
        "eastup":               "東邊",
        "westup":               "西邊",
        "northdown":            "北邊",
        "southdown":            "南邊",
        "eastdown":             "東邊",
        "westdown":             "西邊",
        "northeast":            "東北",
        "northwest":            "西北",
        "southeast":            "東南",
        "southwest":            "西南",
        "up":                   "上面",
        "down":                 "下面",
	"out":				"外面",
        "enter":                "裡面",
        "gate":                 "門裡",
]);

void create()
{
        set("short", "太古飛船內");
        set("long", "
這裡依照從太古時代由大神設計出來的巫師交通秘密武器--太古飛船壹號機
但是由於巫師太過大意，把壹號機的設計圖遺留在世界上，後來被地上的人
們發現，便開始了他們的航空時代，牆壁上貼有一張"HIR"說明手冊(book)"HIW"，旁邊
還有許\多"HIR"窗戶(window)"HIW"可以往外看

飛船指令： 下船(exit)

");
        set("objects",([
            __DIR__"../npc/lady":1,
	]));
	set("heal", 10); // 使用次數限制
set("item_desc", ([ 
  "book":"
說明手冊上寫著：

歡迎搭乘巫師型太古飛船, 這是最新型的太古飛船
您可以操作的方法如下 :

raise   升起飛船
descend 降落飛船
move    移動飛船
laser   發動雷射砲
exit    下飛船

另外, 窗外景色很美, 大家可以看看

"]));
        set("no_kill", 1);
        set("no_cast", 1);
	set("no_fight", 1);
	set("no_exert", 1);
        setup();
}

void init()
{
	if( !previous_object() || !userp(previous_object()) ) return;
	welcome(previous_object());
        add_action("do_exit", "exit");
        add_action("do_raise", "raise");
        add_action("do_descend", "descend");
        add_action("do_move", "move");
        add_action("do_laser", "laser");
        add_action("do_look", "look");
}

void welcome(object ob)
{
	if( objectp(ob->query("boat")) )
		write(HIY"\n飛船廣播器：感謝您搭乘本飛船。\n\n"NOR);
	else {
		write(HIY"\n飛船廣播器：不是從正確途徑搭乘本飛船的乘客必須立刻下船。\n\n"NOR);
		write(HIB"你被飛船從垃圾排出管排放出來。\n\n"NOR);
		ob->move(ob->query("startroom"));
		ob->delete("boat");
	}
	return;
}

int do_exit(string what)
{
	object me = this_player();
	object boat = me->query("boat");
	if( !objectp(this_player()->query("boat")) )
        return notify_fail("你並非正常登機，所以請用recall或quit或suicide離開。\n");
if(boat->query_temp("fly")==1)
        return notify_fail("飛船現在正浮在半空中，你一出去只有死路一條!!\n");

        write(HIB"你打開飛船艙門往外跳\n"NOR);
        tell_room(environment(this_player()),""+this_player()->query("name")+"向大家揮揮手說道：BYE!BYE!我走囉 ! 然後就往外跳~~\n",({this_player()}));
        this_player()->move(environment(boat));
        tell_room(environment(this_player()),""+this_player()->query("name")+"突然從天而降跳下來，差點壓到你!!\n",({this_player()}));
        this_player()->delete("boat");
return 1;
}

int do_raise(string what)
{
	object me, boat;
	me = this_player();
	boat = me->query("boat");
	if( !objectp(me->query("boat")) )
        return notify_fail("你並非正常登機，所以無法駕駛太古飛船。\n");
if(boat->query_temp("fly")==1) {
        write("飛船已經升在空中了。\n");
        return 1;
        }
if(this_object()->query("heal")<1) {
        write("飛船已嚴重損壞...無法再次起飛。\n");
        return 1;
        }

        write(HIB"你前拉太古飛船的控制把......飛船逐漸往上升起....\n"NOR);
        tell_room(environment(boat),HIY"太古飛船的機艙門收了起來....開始運轉渦輪機.....逐漸浮往天空!!\n"NOR,({this_player()}));
        tell_room(environment(this_player()),"你感覺飛船晃動了一下....開始往上升起!!\n",({this_player()}));
        boat->set_temp("fly",1);
environment(this_player())->set("long","
這裡依照從太古時代由大神設計出來的巫師交通秘密武器--太古飛船壹號機
但是由於巫師太過大意，把壹號機的設計圖遺留在世界上，後來被地上的人
們發現，便開始了他們的航空時代，牆壁上貼有一張"HIR"說明手冊(book)"HIW"，旁邊
還有許\多"HIR"窗戶(window)"HIW"可以往外看

飛船運轉中，不能下船

"); 
return 1;
}


int do_descend(string what)
{
	object me, boat;
	me = this_player();
	boat = me->query("boat");
	if( !objectp(me->query("boat")) )
        return notify_fail("你並非正常登機，所以無法駕駛太古飛船。\n");
if(!boat->query_temp("fly"))
        return notify_fail("飛船已經降落到地面上了。\n");

        write(HIB"你後推太古飛船的控制把......飛船逐漸往下降落到地面上....\n"NOR);
        tell_room(environment(boat),HIY"太古飛船緩緩的降落到地面上....機艙門逐漸打開....\n"NOR,({this_player()}));
        tell_room(environment(this_player()),"你感覺飛船晃動了一下....開始下降!!\n",({this_player()}));
     boat->delete_temp("fly");
environment(this_player())->set("long","
這裡依照從太古時代由大神設計出來的巫師交通秘密武器--太古飛船壹號機
但是由於巫師太過大意，把壹號機的設計圖遺留在世界上，後來被地上的人
們發現，便開始了他們的航空時代，牆壁上貼有一張"HIR"說明手冊(book)"HIW"，旁邊
還有許\多"HIR"窗戶(window)"HIW"可以往外看

飛船指令： 下船(exit)

"); 
return 1;
}
int do_move(string what)
{
mapping exit;
string dir;
	object boat, env, me;
string str, *dirs,title,bon;

	me = this_player();
	boat = me->query("boat");
	env = environment(boat);

	if( !objectp(me->query("boat")) )
        return notify_fail("你並非正常登機，所以無法駕駛太古飛船。\n");
if(boat->query_temp("fly")!=1)
        return notify_fail("要開動飛船得先把飛船升上空中...難道你要讓他在地上開!?\n");
if(!what)
        return notify_fail("你想把飛船開往那個方向？\n");
if(!mapp(exit = env->query("exits")) || undefinedp(exit[what])) {
        this_object()->add("heal",-1);
        tell_room(environment(this_player()),HIR"突然飛船搖晃的十分劇烈~~~好像撞倒了牆壁 @@\n"NOR,({this_player()}));
        write(HIR"你把飛船開去撞牆壁了!!\n"NOR);
if(this_object()->query("heal") < 1) {
        tell_room(environment(this_player()),HIR"飛船廣播：由於駕駛員技術過差...飛船撞毀而緊急迫降...\n"NOR,({this_player()}));
        write(HIR"飛船終於被你撞壞嚕....緊急迫降到地面上\n"NOR);
tell_room(environment(boat),HIW"飛船突然一頭哉下來....差點壓死你!!\n"NOR,({boat}));
        boat->delete_temp("fly");
environment(this_player())->set("long","
這裡依照從太古時代由大神設計出來的巫師交通秘密武器--太古飛船壹號機
但是由於巫師太過大意，把壹號機的設計圖遺留在世界上，後來被地上的人
們發現，便開始了他們的航空時代，牆壁上貼有一張"HIR"說明手冊(book)"HIW"，旁邊
還有許\多"HIR"窗戶(window)"HIW"可以往外看

飛船指令： 下船(exit)

"); 
}
return 1;
}

        if( !undefinedp(default_dirs[what]) )
                dir = default_dirs[what];
        else
                dir = what;

        tell_room(environment(boat),HIY"太古飛船的引擎轟隆轟隆的發動.....緩緩的往"+dir+"開了過去\n"NOR,({this_player()}));
        boat->move(exit[what]);
        tell_room(environment(boat),HIY"太古飛船轟隆轟隆的開了過來\n"NOR,({this_player()}));
write(HIB"你將飛船往"+dir+"開過去!!你來到了"+environment(boat)->query("short")+"\n"NOR);
        return 1;
}

int do_look(string what)
{
	object me, boat, where;
	me = this_player();
	if( !objectp(this_player()->query("boat")) )
        return notify_fail("你並非正常登機，滾!!\n");
if(what == "window") {
		boat = me->query("boat");
		where = environment(boat);
write(HIW"你把頭探出窗外看....這裡看起來像是....\n\n"NOR);
        "/cmds/std/look"->look_room(this_player(), where);              
return 1;
}}

int do_laser(string what)
{
	object me, boat, ob;
	me = this_player();
	boat = me->query("boat");
	if( !objectp(me->query("boat")) )
        return notify_fail("你並非正常登機，所以無法使用雷射砲。\n");
if(this_player()->query("level") < 20)
        return notify_fail("這是即危險致命武器...LV20以上的人才能用!!\n");
if(!what)
        return notify_fail("你想轟誰？\n");

        if( !(ob = present(what, environment(boat))))
                return notify_fail("外面沒有"+what+"這個人。\n");
if(ob==boat)
        return notify_fail("這麼想死是嗎？\n");

        write(HIB"你冷冷的說道：「那...去死吧！」按下雷射砲發射按鈕........\n飛船瞬及轟出一道高能雷射瞬間把"+ob->query("name")+""HIB"擊斃了!!\n\n"NOR);
        tell_room(environment(this_player()),HIR"你感覺飛船外面發出巨大的響聲....一個直覺告訴你...又死了一個人了!!\n"NOR,({this_player()}));
     ob->receive_damage("hp",20000);
        tell_room(environment(ob),HIW"突然一道高能光束從飛船上射出，一瞬間便把"+ob->query("name")+"擊斃了!!\n"NOR,({ob}));
        tell_object(ob,HIW"\n突然飛船發出極大的光線...正當你睜不開眼睛時....你已經什麼都不知道了..."+NOR+"\n");

return 1;
}

