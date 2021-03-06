#include <ansi.h>
inherit NPC;
void create()
{
       set_name(CYN"吟遊詩人"NOR,({"bard"}));
       set("long",@LONG
    一名長髮飄逸的女性，上半身僅以一塊絲綢輕輕的包覆著，雪白的雙
手彈撥著豎琴，清脆的琴聲緩和了你心中的空虛，細微卻又清晰的歌聲洗
盡了你身上的風塵，你只想忘掉一切，徘徊在美麗的傳說之中。
LONG);
       set("gender","女性");
       set("age", 27);
       set("level", 50);

       set("chat_chance", 3);
       set("chat_msg", ({
            "吟遊詩人正撥著豎琴，唱著「凡琴斯島的傳說」。\n",
             }));
       set("talk_reply",".....(噓∼別吵，吟遊詩人正唱著凡琴斯島的傳說，你可以靜靜的聆聽(listen)。)\n");
        setup();
}
void init()
{
        ::init();
        add_action("do_listen","listen");
        add_action("do_stop","stop");
}
int do_listen()
{
        object me=this_player();
        int i = random(14)+1;
        if(me->query_temp("fanchins_island_story")>0) return notify_fail("你已經在聆聽了。\n");
        tell_object(me,YEL"你把身體移個較舒適的姿勢，開始聆聽吟遊詩人的歌聲。\n"NOR );
        tell_object(me,"(演唱中可以使用(stop)終止聆聽。)\n" );
        me->set_temp("fanchins_island_story",1);
        call_out("story",3,me,i);
        return 1;
}
int story(object me,int i)
{
        if(environment(me)!=environment(this_object())) 
        {
                me->delete_temp("fanchins_island_story");
                tell_object(me,"你起身離開了「凡琴斯島」旅社。\n" );            
                return 1;
        }
        if(!me->query_temp("fanchins_island_story")) return 1;
        switch(i)
        {
        case 14:
                tell_object(me,HIB"在遙遠的時間和空間中，有個凡琴斯島。\n"NOR );break;
        case 13:
                tell_object(me,CYN"那是海神的花園，是海神之子生長的搖籃。\n"NOR );break;
        case 12:
                tell_object(me,HIM"美麗的島嶼以及美麗的男子，並不是凡人所能見到的。\n"NOR );break;
        case 11:
                tell_object(me,HIG"但是一名失去一切的少女，卻在不幸之中得到了幸福。\n"NOR );break;
        case 10:
                tell_object(me,HIY"海潮送來的少女，讓男子空洞的靈魂有了光芒。\n"NOR );break;
        case 9:
                tell_object(me,HIC"那是有如夢幻的日子，美麗的兩人在夕陽下互吐衷情。\n"NOR );break;
        case 8:
                tell_object(me,HIR"一天，海神的使者來了，要將祂視為玷汙祂純潔兒子的少女送往冥府。\n"NOR );break;
        case 7:
                tell_object(me,HIW"兇猛的巨浪打開了通往黑暗的道路，冥府之主的笑聲在耳邊震盪。\n"NOR );break;
        case 6:
                tell_object(me,HIY"海神之子代替了少女，在臨走前他這樣的說。\n"NOR );break;
        case 5:
                tell_object(me,HIC"別傷心，我的生命不會在冥府消逝，當我戰勝命運，將回到妳身旁。\n"NOR );break;
        case 4:
                tell_object(me,HIG"少女的手終於鬆開了，悲傷的眼眸望著吞噬著愛人的深淵。\n"NOR );break;
        case 3:
                tell_object(me,HIM"少女又失去了一切，只有回憶的曲子留下。\n"NOR );break;
        case 2:
                tell_object(me,CYN"不斷的唱著，不斷的唱著，那首甜蜜卻又哀傷的曲子。\n"NOR );break;
        case 1:
                tell_object(me,HIB"時間之神從不為任何事停留，那少女仍在等待。\n"NOR );break;
        default:
                tell_object(me,MAG"等待她的愛人再度回來，等待那哀傷的曲子不。再。哀。傷。\n"NOR );
                call_out("rest",2,me);
                return 1;
        }
i--;
call_out("story",2,me,i);
}

int rest(object me)
{
        tell_object(me,BLU"等待她的愛人再度回來，等待那哀傷的曲子不。再。哀。傷。\n"NOR );
        switch(random(2))
        {
        case 0:
                tell_object(me,YEL"吟遊詩人唱完，將豎琴整理一下，靜靜的休息著。\n"NOR );
                me->delete_temp("fanchins_island_story");
                return 1;       
        case 1:
                tell_object(me,YEL"吟遊詩人唱完，轉了個調子，又從頭開始唱起。\n"NOR );
                call_out("story",3,me,14);
                return 1;
        }
}

int do_stop()
{
        object me= this_player();
        if(!me->query_temp("fanchins_island_story")) return notify_fail("你並沒有在聆聽演唱。\n");
        me->delete_temp("fanchins_island_story");
        tell_object(me,YEL"你停止聆聽吟遊詩人的演唱。\n"NOR );
        return 1;
}
