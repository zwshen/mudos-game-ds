#include <ansi.h>
inherit NPC;

string book(object me);

string *to_say = ({
  GRN"軒轅烈說﹕真是不知道要怎麼感激他們幾個....\n"NOR,
  "",
  GRN"軒轅烈說﹕不知道他們現在過的可安好？許\久沒去見他們了... \n"NOR,
  GRN"軒轅烈說﹕那本小冊子嘛.. 我已傳授給左使了, 如果你要的話, 就去找左使吧！\n"NOR,
});

string *msg_dunno = ({
        "沒聽說過。\n",
        "無可奉告。\n",
        "嗯....這我可不清楚﹐你最好問問別人吧。\n",
        "對不起﹐你問的事我實在沒有印象。\n"
});

void create()
{
        set_name(HIY"軒轅烈"NOR, ({"shiuan yuan lieh","lieh","yuan lieh","shiuan"}) );
        set("long",@LONG
    這個打扮樸素的中年人就是疾風門的開山祖師
「軒轅烈」，他從小時候就練就了一身硬門的功夫
自幼便有[0;1;31m�[1mZ[1m�[1m�[0m之稱，在一次的偶然巧遇中，竟另創
他徑，武功由外而內，內功竟為大進，在江湖中與
[0;1;33m�[1m�[1m�[1m�[1m�[1m�[1m�[1mx[1m�[1m�[1m [1m [1m�[1mN[1m�[1mb[0m並稱武林兩絕，他在朝庭已效命
許久，年以而立，目前官當大統領，在他 25 歲那
年在家鄉創立的疾風門。
LONG
        );
        set("level",60);
        set("evil",-20-random(50));
        set("combat_exp",59000);
        set("age",80);

        set("chat_chance",8);
        set("chat_msg",({
  (: command("say 最近世事真多變") :),
  (: command("say 天似圓蓋\，地似棋盤") :),
  (: command("say 江南隱居處，不知十昧火") :),
  (: command("exert moon_force recover") :),
}));
        set_temp("class_wind/power",300);
    set("max_ap",6000);

        set("chat_chance_combat",80);
        set("chat_msg_combat",({
  (: command("do wield sword,exert star-sword tian") :),
  (: command("do wield sword,exert star-sword penuma-sword") :),
  (: command("do wield sword,exert moon_force long-arc"):),
  (: command("exert moon_force recover"):),
  (: command("do wield sword,exert star-sword tian") :),
  (: command("do wield sword,exert star-sword nine") :),
  (: command("do wield sword,exert star-sword penuma-sword") :),
  (: command("do wield sword,exert star-sword tian") :),
}));
        set("class1","疾風門");
        set("class2", "疾風門");
        set("adv_class", 2);
        set("title","疾風門創人");
        set("nickname",HIR"武神"NOR);

// -- guild
// ========================================================================
//      導師的屬性分配表(權數) 請 more /doc/wiz/屬性與素質.txt
//      設定屬性分配表, 每一項的值在負9至正10之間
//      而且四項的總和要剛好等於 20
// ========================================================================
        set("guild_gifts",({ 6,5,2,7 }));
// ========================================================================
//      工會導師可以教授的技能列表
// ========================================================================
        set("guild_skills",([   // 難度, 等級1 可學到的技能等級倍率, 上限
  "star-sword" : ({ 150, 4, 80 }),
  "moon_force" : ({ 175, 5, 85 }),
]));
// -- guild

        set("flurrydodge",1);

        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("combat",100);
        set_skill("sorgi_sword",100);
        set_skill("force", 100);
        set_skill("moon_force",100);
        set_skill("fogseven",100);

    set_skill("star-sword",100);
    map_skill("sword","star-sword");
        map_skill("dodge","fogseven");

        set("inquiry", ([
  "小冊子" : (: book :),
  "冊子" : (: book :),
]));


        setup();
        carry_object(__DIR__"wp/sevenstar")->wield();
        carry_object(__DIR__"eq/flurryneck.c")->wear();
        carry_object(__DIR__"eq/hookgloves")->wear();
        carry_object(__DIR__"eq/incrystate")->wear();
}

void init()
{
        object me = this_player(), ob = this_object();
        ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_say", "say");

        if( me->query_temp("find_lieh") )
        {
                me->delete_temp("find_lieh");
                me->set_temp("meet_lieh",1);
                call_out("find_lieh",2,me,ob);
        }
}

void find_lieh(object me,object ob)
{
        message_vision("$N看見了$n，就將光明左使尋找$n之事告之。\n",me,ob);
        command("sigh");
        command("say "+RANK_D->query_respect(me)+"請你轉告他說我在近日之內會回去。");
        command("thank "+me->query("id"));
        return;
}

string book(object me)
{
        me = this_player();
        if( me->query_temp("book") )
                return "那本小冊子？.... 是幾年前幾位高人給我的嗎？\n";
}

int do_say(string arg)
{
        object me = this_player();
        if( arg == "是" && me->query_temp("book") )
        {
                message_vision(YEL"$N說﹕"+arg+"\n"NOR, me);
                me->set_temp("get_book", 1);
                call_out("delay", 2, me, 0);
                return 1;
        }
        return 0;
}

void delay(object me, int flag)
{
        message_vision(to_say[flag], this_object());
        if( ++flag < sizeof(to_say) )
        {
                call_out("delay", 1, me, flag );
                return;
        } 
        tell_object(me, HIC" 說到這, 你知道你應該去找誰要冊子了！ \n"NOR);
        return;
}

void delay2(object me, object ob)
{
        message_vision(GRN"軒轅烈說﹕這..這...不是當初我在山上所用的元氣石嗎？\n"NOR, ob);
        message_vision(GRN"軒轅烈緊握著$N的手說：謝謝你了, "+ RANK_D->query_respect(this_player()) + ", 既然你幫了我這個忙, 我就收你為徒吧！\n"NOR, me, ob);
        return;
}

void delay3(object me)
{
        message_vision(GRN"軒轅烈說﹕這..這...不是當初我在山上所用的元氣石嗎？\n"NOR, me);
        message_vision(GRN"軒轅烈緊握著$N的手說：謝謝你了, "+ RANK_D->query_respect(this_player()) + ", 既然你幫了我這個忙, 我就送這個小禮給你吧！\n"NOR, me);
        return;
}

int accept_object(object me, object ob)
{
        if( !ob->id("open-war-stone") ) return 0;
        else if( me->query("class1") == "疾風門" && me->query("level") == 25 && !me->query("class2") && me->query_temp("got_stone") )
        {
                me->delete_temp("got_stone");
                me->set("class2", "疾風門");
                me->create_family("疾風門進階", 3, "劍士");
                me->set("guild_rank", WHT"經年歷練的新劍士"NOR);
                message_vision("$N給$n一" + ob->query("unit") + ob->name() + "。\n", me, this_object());
                me->set("adv_class", 2);
                me->set("guild_gifts",({ 4,6,5,5 }));
                message("world:world1:vision", WHT"超級小條："HIR" [ " + me->name(1) + " 成為了軒轅烈門下正式的劍士了！ ] \n"NOR, users());
                write_file("/u/c/cominging/log/wind_adv.log" , sprintf("%s became the member of advenced wind party at %s\n", geteuid(me), ctime(time())));
                call_out("delay2", 1, me, ob);
                return 1;
        }
        else
        {
                message_vision("$N給$n一" + ob->query("unit") + ob->name() + "。\n", me, this_object());

                if( !me->query_temp("get_heal_stone") && !this_object()->query("give_heal_stone") )
                {
                        object stone = new(__DIR__"obj/heal_stone.c");
                        stone->move(me);
                        destruct(ob);
                        message_vision("$N給$n一" + stone->query("unit") + stone->name() + "。\n", this_object(), me);
                        me->set_temp("get_heal_stone", 1);
                        this_object()->set("give_heal_stone", 1);
                        call_out("delay3", 1, me);
                }
                else
                {
                        me->add("exp", 3000);
                        tell_object(me, "你得到了 3000 點經驗。\n");
                }
                return 1;
        }
}

int do_skill_list(string arg)
{
        return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
        int ss = this_player()->query_skill("star-sword"), temp;
        if( this_player()->query("class2") != "疾風門" )
                return notify_fail("你不是疾風進階劍士！\n");
        if( arg=="moon_force" 
        
                if( this_player()->query_skill( "moon_force", 1 ) == 0 
                return notify_fail("你並沒有殘月心法基礎，因此無法修練。\n")
        
        if( arg == "star-sword" 
        
        temp = this_player()->query_skill(arg) / 30
                if( this_player()->query("popularity") < temp 
                        return notify_fail("你似乎沒有足夠的聲望來向" + this_object()->name(1) + "領教昂星劍法！\n")
        
        return GUILDMASTER->do_skill_train(this_object(),this_player(),arg);
void train_skill_cost(object me, string skill
    int temp = (skill=="star-sword") ? me->query_skill(skill)/30 : 0
        me->add("popularity",-temp)
        return
int do_advance(string arg
        object me = this_player()
        int pop = me->query("popularity"), lev = me->query("level") - 21
        if( me->query("class2") != "疾風門" 
                return notify_fail("你不是疾風進階劍士！\n")
        if( (( !arg || arg == "level" ) && pop < (lev*lev+1)) || ( pop < 3 ) 
                return notify_fail("你的聲望不足用以升級！\n")
       
        return GUILDMASTER->do_advance(this_object(), me, arg)
// advance 成功後 GUILDMASTER 會自動呼�
void advance_cost(object me,string arg
        int cost = ( me->query("level")-21 ) * ( me->query("level") - 21 )
        if( !arg || arg=="level" 
                me->add("popularity",-cost )
        else if( me->query("popularity") < 3 
                me->set("popularity",0 ); 
        else me->add("popularity",-3)
        me->save()
        return
string guild_rank(object me
        string rank
        int lv, force, sword
        force = me->query_skill("force", 2)
        sword = me->query_skill("star-sword", 1)
        lv = ( me->query("level") - 25 ) / 6
        if ( sword > 80 && force > 99 && force > sword ) rank = HIW"劍術高超的內功\師"NOR
    else if ( force > 80 && sword > 99 && sword > force ) rank = HIW"內力渾厚的劍術士"NOR
        else if ( force > 99 && sword > 99 ) rank = HIC"登峰造極"HIW"全能劍士"NOR
        else if ( force > 70 ) rank = WHT"內功\高明的疾風人"NOR
        els
        {       switch( lv 
                
                        case 0: rank = WHT"經年歷練的新劍士"NOR; break
                        case 1: rank = WHT"頗有名氣的小劍士"NOR; break
                        case 2: rank = WHT"功\力不凡的劍術師"NOR; break
                        case 3: rank = WHT"疾風門的出師高徒"NOR; break
                        case 4: rank = HIW"縱橫天下一代劍士"NOR; break
                        default: rank = WHT"疾風進階千錘百煉"NOR
                
        
        return rank
void die(
        object ob
        if( !ob = query_temp("last_damage_from") 
                ob = this_player(1)
        if( !ob )
        
                ::die()
                return
        
        message("world:world1:vision", WHT"\n 超級爛條： [ 傳聞"HIW"疾風門門主 "HIY"軒轅烈 "NOR WHT"在 "HIR + ob->name(1) + " "NOR WHT"的手下，嚥下了命中的最後一口氣。 ] \n\n"NOR, users())
        ob->add("popularity", 100000); //聲�
        ::die()
        return
