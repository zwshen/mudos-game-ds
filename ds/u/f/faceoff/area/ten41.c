inherit ROOM;
static int on_journey = 0;
private void confirm_journey(string arg);

void create()
{
        set("short","青石路");
        set("long","你正沿青石路走向天梟冶藥一派。\n");
        set("distance",5);             //設定兩地的距離。
        set("to_room",__DIR__"pill1");       //設定目的。
        set("from_room",__DIR__"ten40");     //設定起點。
    set("outdoors","land");
        
        setup();
}

varargs int do_look(object me, string arg)
{
        if( on_journey==1 )
                write("你正沿青石路走向天梟冶藥一派, 如果你想回頭﹐可以打 return。\n");
        else if( on_journey==-1 )
                write("你正往回走向原來出發的地方。\n");
        return 0;
}

void init()
{
        add_action("do_return", "return");
        add_action("do_look","look");
        if( this_player() ) {
                if( userp(this_player()) ) {
                        write("你確定要離開這個區域嗎﹖[y/n]");
                        input_to("confirm_journey");
                } else
                        confirm_journey("no");
        }
}

private void confirm_journey(string arg)
{
        if( arg[0]=='y' ) {
                on_journey = 1;
                call_out("arrive_destination", query("distance"), this_player());
                this_player()->start_busy(query("distance") );
                do_look(this_player());
        } else if( arg[0]=='n' ) {
                this_player()->move(query("from_room"));
                destruct(this_object());
        } else {
                write("你確定要離開這個區域嗎﹖[y/n]");
                input_to("confirm_journey");
        }
}

private void arrive_destination(object me)
{
        string res;

        if( !objectp(me) ) return;

        if( on_journey == 1 ) res = me->move(query("to_room"));
        else    res = me->move(query("from_room"));

        if( !res ) {            //沒有目的或是起點。
                this_player()->start_busy(query("distance") );
                call_out("arrive_destination", 5, me);
                return;
        }
        destruct(this_object());
}

private int do_return(string arg)
{
        if(on_journey==-1)
               return notify_fail("你已正在回途中了。\n");
        on_journey = -1;
        write("你開始往回走。\n");
        set("long","你正沿青石路走回十萬大山.\n");
        return 1;
}
