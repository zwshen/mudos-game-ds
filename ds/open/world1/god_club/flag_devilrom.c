inherit ROOM;

string *members = ({ });
void create()
{
        set("short", "魔界");
        set("long", @long
魔界，是個充滿著罪惡的深淵，更是天地穹蒼萬惡邪源的聚集處
，隨處都可看見爬滿著不停苦掙扎的魍魎魑魅以及無數千奇百怪的恐
怖事物，使人看到都不禁打了個冷顫，據說裡面藏著遠古時代蚩尤的
絕世武功，曾有無數勇者進來找尋，至今仍無一生還的消息傳出。

long);
        set("exits", ([
  "northwest" : __DIR__"ladd-2",
  "northeastup" : __DIR__"vip2_room.c",
]));
        set("light", 1);
        setup();
        set("stroom", 1);
}
/*
int valid_leave(object me, string dir)
{
        if( dir == "northeastup" && !wizardp(me) )
        {
                if( load_object(__DIR__"vip2_room.c") )
                {
                        if( member_array(getuid(me), members) != -1 || getuid(me) == "exri" )
                        {
                                tell_room(this_object(), me->name()+"低聲喃喃唸了幾句咒語，身影也慢慢的消失了•••\n", ({ me }));
                                me->move(__DIR__"vip2_room.c");
                                tell_room(load_object(__DIR__"vip2_room.c"), me->name()+"從底下漸漸上升至此地。\n", ({ me }));
                                return 1;
                        }
                        else return notify_fail("你沒有得到 exri 的許\可無法進入。\n");
                }
                else return notify_fail("方向出口房間有誤。\n");
        }
        else return ::valid_leave(me, dir);
}

void init()
{
        if( getuid(this_player()) == "exri" )
        {
                add_action("do_control", "control");
        }
}

int do_control(string arg)
{
        if( !arg ) return notify_fail("格式: control <人名>\n");
        if( member_array(arg, members) != -1 )
        {
                members -= ({ arg });
                write("刪除可進出人物 "+arg+"。\n");
                return 1;
        }
        else
        {
                members += ({ arg });
                write("增加可進出人物 "+arg+"。\n");
                return 1;
        }
        return notify_fail("格式: control <人名>\n");
}
string *query_members() { return members; }
*/
