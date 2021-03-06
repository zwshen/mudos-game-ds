#include <ansi.h>
inherit ITEM;

/*-------------會飛往的區域-------------*/
string *areas = ({
// "/open/world1/whoami/birdarea/",    //東北澤林
   "/open/world1/acme/area/",          //天城
   "/open/world1/tmr/area/",           //滄縣
   "/open/world1/wu_sha_town/",        //無砂鎮
   "/open/world1/cominging/purple_sun/"//紫陽山
});

void create()
{
    set_name(HIR"定時炸彈"NOR,({ "bomb" }));
    if( clonep() )
    set_default_object(__FILE__);
    else
    {
       set("no_sell",1);
       set("no_drop",1);
       set("no_give",1);
       set("no_put",1);
       set("no_get",1);
       set("unit","顆");
       set("value",0);
    }
    setup();
}

void init()
{
    add_action("do_throw", "throw");
}

/*-------------判別可以投擲的出口-------------*/
int do_throw(string arg)
{
    object me = this_player();
    object ob = this_object();
    mapping exits = environment(me)->query("exits");

    if(!arg)
       return notify_fail("你要往哪個方向丟擲？\n");
    if(sizeof(exits) < 1)
       return notify_fail("這裡沒有任何的出口。\n");
    if(member_array(arg,keys(exits)) == -1)
       return notify_fail("這裡沒有"+arg+"這個出口。\n");

    message_vision("$N朝"+arg+"丟出了一顆$n。\n",me,ob);
    tell_room(exits[arg],me->name(1)+"朝這裡丟了一顆"+ob->name()+"。\n");

    ob->move(exits[arg]);
    call_out("follow",0);
    return 1;
}

/*-------------判定隨機爆炸-------------*/
int follow()
{
    object *list,ob,who;
    ob = this_object();
    list = all_inventory(environment(ob));
    who = list[random(sizeof(list))];

    // 設定忙碌
    foreach(object user in list)
    {
       if(!userp(user) || !living(user)) continue;
       message_vision("$N癡癡的望著$n。\n",ob,user);
       user->start_busy(3);
    }
    switch( random(10)+1)
    {
       case 1..9 :
            call_out("bamboo",3,list);
            break;
       default :
            message_vision(HIM"什麼事也沒有發生, 啞巴了￣口￣a\n"NOR,ob);
            destruct(ob);
            break;
    }
    return 1;
}

/*-------------攻擊所有人-------------*/
int bamboo(object *list)
{
    object ob;
    string *file,dir,room;
    ob = this_object();
    foreach(object user in list)
    {
        if(!living(user) || !userp(user)) continue;

        // 取得*areas中檔案名稱
        dir = areas[random(sizeof(areas))];
        file = get_dir(dir);
        room = dir + file[random(sizeof(file))];

        // 炸飛的機率
        switch( random(10)+1 )
        {
           case 1..9 :
                message_vision("\n\n\n\t["HIC" $N咻 ∼ 的一聲被炸飛到"+room->query("short")+NOR" ]。\n\n\n\n",user);
                tell_object(this_player(),user->name(1)+"被炸飛到 "+room->query("short")+"。\n");
                user->move(room);
                break;
           default :
                message_vision(HIY"$N東躲西藏，逃過了炸彈的波及。\n"NOR,user);
                tell_object(this_player(),user->name(1)+"東躲西藏，逃過了炸彈的波及。\n");
                break;
        }
    }
    destruct(ob);
    return 1;
}
