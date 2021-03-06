// 山貓(adx) by snow 2000-05-15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "比武場貴賓席");
	set("long", @LONG
這里是比武場的貴賓席，几張紫檀太師椅排成一行，每張太師椅上面
都披著一張虎皮。只有夢幻七域的巫師才有資格坐在這裡。
LONG);
	set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"biwutai",
		"down" : __DIR__"houtai",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
        object tai=load_object(__DIR__"biwutai");
        object *inv=all_inventory(tai);
	object ob, where;
        int i=sizeof(inv);

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);

	if ( !wizardp(me) && dir=="south" ) {
		if( ob->query("start/start") && !me->query("biwu_fighter") )
			return notify_fail("比武已經開始了，你不是選手不能上台。\n");
		if(i>=2)
			return notify_fail("比武台上已經有兩名選手，你現在不能上台。\n");
	}
        return ::valid_leave(me, dir);
}

void init()
{
//	add_action ("do_start","start");
	add_action ("do_urged","urged");
	add_action ("do_check","check");
	add_action ("do_next","next");
	add_action ("do_xsave","xsave");
	add_action ("do_work","quit");
}

int do_urged()
{
	object where, ob, ob1, ob2;
	string id1, id2;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);

	if(!ob->query("start"))
		return notify_fail("比武尚未開始啊！\n");

	id1=ob->query("start/biwu_fighter1");
	id2=ob->query("start/biwu_fighter2");

	if(id1) ob1=find_player(id1);
	if(id2) ob2=find_player(id2);

	if(!ob1) ob->keep_biwu(id2);
	if(!ob2) ob->keep_biwu(id1);

	message_vision(CYN"$N把"+ob1->query("name")+"和"+
		ob2->query("name")+"一腳踹上比武台！\n"NOR, this_player());
	if(environment(ob1)->query("short")!="比武台") {
		message_vision (CYN"公平子一腳把"+ob1->query("name")+
		"踹上比武台，嘴里嘟噥著：怎麼拖拖拉拉的！\n"NOR, ob1);
		ob1->move(__DIR__"biwutai");
	}
	if(environment(ob2)->query("short")!="比武台") {
		message_vision (CYN"公平子一腳把"+ob2->query("name")+
			"踹上比武台，嘴里嘟噥著：怎麼拖拖拉拉的！\n"NOR, ob2);
		ob2->move(__DIR__"biwutai");
	}
	return 1;
}

int do_start(string arg)
{
	object where, ob;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);
	if(!arg)
		return notify_fail("你要開始什麼？？！\n");
	ob->do_start(arg);
	return 1;
}

int do_check()
{
	object where, ob;
	object me=this_player();
	int i, j, k, a, b, c;
	string arg, id, msg, *str, *menpai;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);
	i=ob->query("biwudahui");
	j=ob->query("start/lunxu");
	k=(ob->query("start/huihe")-1);
	arg=ob->query("start/start");
	menpai=ob->query("fenzu");

	if(!arg)
		return notify_fail("目前還沒有開始比武！\n");

	if(arg=="xunhuan") {
		message_vision(WHT"第"+CHINESE_D->chinese_number(i)+"屆比武大會！\n"NOR, me);
	} else {
		message_vision(WHT"正在進行"MAG+arg+WHT"掌門大弟子選拔比武！\n"NOR, me);
	}

	message_vision (WHT"第"+CHINESE_D->chinese_number(j)+"輪！\n"NOR, me);

	for(a=1; a<(sizeof(menpai)+1); a++) {
		msg=WHT"第"+CHINESE_D->chinese_number(a)+"組：";
		str=ob->query("fenzu/"+a+"/");
		for(b=1; b<(sizeof(str)+1); b++) {
			id=ob->query("fenzu/"+a+"/"+b+"");
			c=ob->query("jifen/"+id);
			msg+="("+id+") 積分=="+c+"\t";
		}
		message_vision (WHT""+msg+"\n"NOR, me);
	}
	message_vision (WHT"\n現在進行到第"+CHINESE_D->chinese_number(k)+"回合！\n"NOR, me);
	return 1;
}

int do_xsave()
{
	object where, ob, me;
	me=this_player();
	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);
	message_vision (CYN"比武進度儲存完畢！\n"NOR, me);
	ob->save();
	return 1;
}

int do_next(string arg)
{
	object where, ob, me;
	me=this_player();
	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);
	message_vision (CYN"繼續進行下一輪比武！\n"NOR, me);
	if(!arg) {
		ob->keep_biwu("adx");
	}
		ob->keep_biwu(arg);
	return 1;
}

int do_work()
{
	write("這裡不能使用這個指令！\n");
	return 1;
}
