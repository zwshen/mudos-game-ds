// 山貓(adx) by snow 2000-05-15

inherit ROOM;

void create ()
{
	set ("short", "比武看台");
	set ("long", @LONG
你站在比武場前一處大看台，看台上有一排排的木製條凳，你可
以坐在這裡，比武台上一切比武過招你都能看得非常清楚。這裡還提供免
費的飲食。
LONG);
	set("no_fight",1);
	set("no_clean_up",1);
	set("exits", ([
		"up"   : __DIR__"biwutai",
		"south"   : __DIR__"zoulang",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object tai=load_object(__DIR__"biwutai");
	object *inv=all_inventory(tai);
	object ob, where;
	int i,j;
	for(j=0;j<sizeof(inv);j++)
		if( userp(inv[j]) && !wizardp(inv[j])  ) i++;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	if(!objectp(ob=present("da go ko", where)))         return ::valid_leave(me, dir);

	if ( !wizardp(me) && dir=="up" ) {
		if( ob->query("start/start") && !me->query("biwu_fighter") )
			return notify_fail("比武已經開始了，你不是選手不能上台。\n");
		if(i>=2)
			return notify_fail("比武台上已經有兩名選手，你現在不能上台。\n");
	}
        return ::valid_leave(me, dir);
}
