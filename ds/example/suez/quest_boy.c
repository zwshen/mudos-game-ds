#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
void start();
void die();
void reok();
//決定玩家解決任務後所獲得屬性，第一項為光明，第二項為中立，第三項為黑暗。//
int *sarsass = ({ 1, 1 , 1 });
void create()
{
        set_name( "倒在血泊中的少年", ({ "boy" }));
        set("long", "一個倒在血泊中的少年。\n");
        set("level",10);
        set("gender", "男性");
        set("age", 17);
        set("exp", 70);
        set("chat_chance", 15 );  
        set("chat_msg", ({        
                "你覺得有點不太對勁。\n",
                "少年有氣無力的望著你，眼中充滿了絕望。\n",
        }) );
        set("talk_reply","我...我把這只戒指還你.....放過我吧！...我還不想死........");
        set("inquiry", ([
        "戒指" : "我家被那些商人強制收購去了...我氣不過....身上又沒錢了....所以我才.....。\n",
        ]));
        set("schedule",
        ([
        "03" : (: reok :),
         "23" : (: start :),
        ]));


        setup();
        carry_object(__DIR__"/eq/ring");
}



void init()
{
        int hpx;
        ::init();
        hpx= this_object()->query("max_hp");
        this_object()->receive_damage("hp", hpx*2/5 );
        add_action("do_steal","steal");
       add_action("do_say","say");
}
void start()
{
        object npc1,npc2;
     string AREA = "../port_"+(15+random(11))+"";
        npc1 = this_object();
        npc2 = new(__DIR__"bussniss_mn");
        if(!find_object("../port_b6")) return;
        npc1->move("../port_b6");
        npc2->move(""+AREA+"");
        npc2->die();
        tell_room(environment(npc2),HIR"在你面前發生了一起強盜殺人案，你看見犯人往下水道的方向逃逸！幾個拿武器的人已追了過去！\n"NOR);
        tell_room("../port_b1",HIR"上方傳來一陣喧鬧聲，一道黑影突然從你身後竄過。\n"NOR);
        tell_room("../port_b2",HIR"北方傳來一陣喧鬧聲，一道黑影突然從你身後竄過。\n"NOR);
        tell_room("../port_b3",HIR"下水道的入口處似乎傳來一陣急促的腳步聲。\n"NOR);
        tell_room("../port_b4",HIR"你被一個人影撞了一下，只見那人影站立不穩向後一跌，竟然穿過牆壁了！\n"NOR);
        tell_room("../port_b5",HIR"北方傳來奇怪的聲響。\n"NOR);
        //tell_room("../port_c4",HIR"下水道的入口處似乎傳來一陣急促的腳步聲。\n"NOR);
        //tell_room("../port_c5",HIR"下水道的入口處似乎傳來一陣急促的腳步聲。\n"NOR);
        //tell_room("../port_c6",HIR"下水道的入口處似乎傳來一陣急促的腳步聲。\n"NOR);
        //tell_room("../port_c7",HIR"下水道的入口處似乎傳來一陣急促的腳步聲。\n"NOR);
        //tell_room("../port_c8",HIR"下水道的入口處似乎傳來一陣急促的腳步聲。\n"NOR);
        //tell_room("../port_c9",HIR"下水道的入口處似乎傳來一陣急促的腳步聲。\n"NOR);
        return;
}
void greeting(object ob)
{
        int l,n,d;
        mixed *m=ob->query("sarsass_2");
        if( !ob || environment(ob) != environment() ) return;
        if( !ob->query("sarsass_2") && !this_object()->query_temp("ring"))
        {
                 ob->set_temp("sarsass_test_q",1);
                 tell_object(this_player(),@LONG
這是一名搶奪戒指並殺害被害者的少年，你現在必須決定如何處置他:
一、殺人償命，殺了他將戒指拿回來。
二、看他可憐，當作沒看到他走開好了。
三、可以放過他，但是他必須將戒指還回來才行。(say 戒指)

LONG);  
}else
{
        l = m[0];
        n = m[1];
        d = m[2]; 
        if(l >= n && l > d)  tell_object(ob,"您上次解決此問題的總和評價為光明。\n");
        if(n > l || n > d )  tell_object(ob,"您上次解決此問題的總和評價為中立。\n");
        if(d >= n && d > l)  tell_object(ob,"您上次解決此問題的總和評價為黑暗。\n");
        if(l = d )  tell_object(ob,"您上次解決此問題的總和評價為中立。\n");     
}
}
int do_steal(string arg)
{
 if(arg=="boy")
 {
 tell_object(this_player(),"因為功\力不夠寫出對應此行動的程式，所以請不要用這種方式來解決此Quest。\n");
}
 return 1;
}
int do_say(string arg)
{
 object me = this_player();
 mixed *m=me->query("sarsass_2");
 if(arg=="戒指" && !me->query("sarsass_2") && me->query_temp("sarsass_test_q")>0)
 {
 tell_object(me,"你對少年說可以放過他，但是戒指必須物歸原主。\n");
 tell_object(me,"少年用沾滿血的手將戒指掏出來。\n");
 command("give ring to " + me->query("id") );
 this_object()->set_temp("ring");
 if(!m)  me->set("sarsass_2",sarsass);
 sarsass = m;
 if(m[0] < m[2]) {sarsass[1]++;
 if(m[0] > m[2]) {sarsass[0]++;
 if(m[0] = m[2]) {sarsass[2]--;
 //紀錄執行這個行為後的屬性改變。//
 me->set("sarsass_2",sarsass);
}
 return 1;
}
void reok()
{               
                destruct(this_object());
}

void die()
{
        object me = this_player();
        mixed *m=me->query("sarsass_2");
        sarsass = m;
        if(environment( this_object() )=="shop.c")
        {
                destruct(this_object());
        }
        else{
         if(!me->query_temp("last_damage_from") )
         me = this_player(1);
         if(me->query_temp("sarsass_test_q")>0 && !me->query("sarsass_2"))
         {
                if(!m)  me->set("sarsass_2",sarsass);
                if(m[0] < m[2]) sarsass[2]++;
                if(m[0] > m[2]) sarsass[1]++;
                if(m[0] = m[2]) sarsass[0]--;
                //紀錄執行這個行為後的屬性改變。//
                me->set("sarsass_2",sarsass);
         }
                ::die();
}}


