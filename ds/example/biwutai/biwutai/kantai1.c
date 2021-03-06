// 山貓(adx) by snow 2000-05-15

inherit ROOM;

void create ()
{
	set ("short", "左看台");
	set ("long", @LONG
這是小雪初晴比武場的左看台，看台上有一排排的木制條凳。你坐在
這里一丈高的比武台上一切比武過招你都能看得非常清楚。這里還提供免
費的飲食。
LONG);
	set("no_fight",1);
	set("no_clean_up",1);
	set("exits", ([
		"up"   : __DIR__"biwutai",
		"northeast"   : __DIR__"houtai",
		"southeast"   : __DIR__"kantai2",
		"south"   : __DIR__"zoulang",
	]));
	setup();
}

void init()
{
	add_action ("do_work","ansuan");
}

int do_work()
{
	write("這里不能使用這個指令！\n");
	return 1;
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

	if ( !wizardp(me) && dir=="up" ) {
		if( ob->query("start/start") && !me->query("biwu_fighter") )
			return notify_fail("比武已經開始了，你不是選手不能上台。\n");
		if(i>=2)
			return notify_fail("比武台上已經有兩名選手，你現在不能上台。\n");
	}
        return ::valid_leave(me, dir);
}
