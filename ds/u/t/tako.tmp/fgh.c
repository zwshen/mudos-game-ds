#include <ansi.h>
inherit NPC;

string book(object me);

string *to_say = ({
  GRN"°aÁÕ¯P»¡¡R¯u¬O¤£ª¾¹D­n«ç»ò·P¿E¥L­Ì´X­Ó....\n"NOR,
  "",
  GRN"°aÁÕ¯P»¡¡R¤£ª¾¹D¥L­Ì²{¦b¹Lªº¥i¦w¦n¡H³\\¤[¨S¥h¨£¥L­Ì¤F... \n"NOR,
  GRN"°aÁÕ¯P»¡¡R¨º¥»¤p¥U¤l¹À.. §Ú¤w¶Ç±Âµ¹¥ª¨Ï¤F, ¦pªG§A­nªº¸Ü, ´N¥h§ä¥ª¨Ï§a¡I\n"NOR,
});

string *msg_dunno = ({
        "¨SÅ¥»¡¹L¡C\n",
        "µL¥i©^§i¡C\n",
        "¶â....³o§Ú¥i¤£²M·¡¡M§A³Ì¦n°Ý°Ý§O¤H§a¡C\n",
        "¹ï¤£°_¡M§A°Ýªº¨Æ§Ú¹ê¦b¨S¦³¦L¶H¡C\n"
});

void create()
{
        set_name(HIY"°aÁÕ¯P"NOR, ({"shiuan yuan lieh","lieh","yuan lieh","shiuan"}) );
        set("long",@LONG
    ³o­Ó¥´§ê¾ë¯Àªº¤¤¦~¤H´N¬O¯e­·ªùªº¶}¤s¯ª®v
¡u°aÁÕ¯P¡v¡A¥L±q¤p®É­Ô´N½m´N¤F¤@¨­µwªùªº¥\¤Ò
¦Û¥®«K¦³[0;1;31mª[1mZ[1m¯[1m«[0m¤§ºÙ¡A¦b¤@¦¸ªº°¸µM¥©¹J¤¤¡A³º¥t³Ð
¥L®|¡AªZ¥\¥Ñ¥~¦Ó¤º¡A¤º¥\³º¬°¤j¶i¡A¦b¦¿´ò¤¤»P
[0;1;33m¾[1mÑ[1m¤[1mÑ[1m¬[1m£[1m´[1mx[1mª[1mù[1m [1m [1m§[1mN[1m¤[1mb[0m¨ÃºÙªZªL¨âµ´¡A¥L¦b´Â®x¤w®Ä©R
³\¤[¡A¦~¥H¦Ó¥ß¡A¥Ø«e©x·í¤j²Î»â¡A¦b¥L 25 ·³¨º
¦~¦b®a¶m³Ð¥ßªº¯e­·ªù¡C
LONG
        );
        set("level",60);
        set("evil",-20-random(50));
        set("combat_exp",59000);
        set("age",80);

        set("chat_chance",8);
        set("chat_msg",({
  (: command("say ³Ìªñ¥@¨Æ¯u¦hÅÜ") :),
  (: command("say ¤Ñ¦ü¶ê»\\¡A¦a¦ü´Ñ½L") :),
  (: command("say ¦¿«nÁô©~³B¡A¤£ª¾¤Q¬N¤õ") :),
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
        set("class1","¯e­·ªù");
        set("class2", "¯e­·ªù");
        set("adv_class", 2);
        set("title","¯e­·ªù³Ð¤H");
        set("nickname",HIR"ªZ¯«"NOR);

// -- guild
// ========================================================================
//      ¾É®vªºÄÝ©Ê¤À°tªí(Åv¼Æ) ½Ð more /doc/wiz/ÄÝ©Ê»P¯À½è.txt
//      ³]©wÄÝ©Ê¤À°tªí, ¨C¤@¶µªº­È¦b­t9¦Ü¥¿10¤§¶¡
//      ¦Ó¥B¥|¶µªºÁ`©M­n­è¦nµ¥©ó 20
// ========================================================================
        set("guild_gifts",({ 6,5,2,7 }));
// ========================================================================
//      ¤u·|¾É®v¥i¥H±Ð±Âªº§Þ¯à¦Cªí
// ========================================================================
        set("guild_skills",([   // Ãø«×, µ¥¯Å1 ¥i¾Ç¨ìªº§Þ¯àµ¥¯Å­¿²v, ¤W­­
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
  "¤p¥U¤l" : (: book :),
  "¥U¤l" : (: book :),
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
        message_vision("$N¬Ý¨£¤F$n¡A´N±N¥ú©ú¥ª¨Ï´M§ä$n¤§¨Æ§i¤§¡C\n",me,ob);
        command("sigh");
        command("say "+RANK_D->query_respect(me)+"½Ð§AÂà§i¥L»¡§Ú¦bªñ¤é¤§¤º·|¦^¥h¡C");
        command("thank "+me->query("id"));
        return;
}

string book(object me)
{
        me = this_player();
        if( me->query_temp("book") )
                return "¨º¥»¤p¥U¤l¡H.... ¬O´X¦~«e´X¦ì°ª¤Hµ¹§Úªº¶Ü¡H\n";
}

int do_say(string arg)
{
        object me = this_player();
        if( arg == "¬O" && me->query_temp("book") )
        {
                message_vision(YEL"$N»¡¡R"+arg+"\n"NOR, me);
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
        tell_object(me, HIC" »¡¨ì³o, §Aª¾¹D§AÀ³¸Ó¥h§ä½Ö­n¥U¤l¤F¡I \n"NOR);
        return;
}

void delay2(object me, object ob)
{
        message_vision(GRN"°aÁÕ¯P»¡¡R³o..³o...¤£¬O·íªì§Ú¦b¤s¤W©Ò¥Îªº¤¸®ð¥Û¶Ü¡H\n"NOR, ob);
        message_vision(GRN"°aÁÕ¯Pºò´¤µÛ$Nªº¤â»¡¡GÁÂÁÂ§A¤F, "+ RANK_D->query_respect(this_player()) + ", ¬JµM§AÀ°¤F§Ú³o­Ó¦£, §Ú´N¦¬§A¬°®{§a¡I\n"NOR, me, ob);
        return;
}

void delay3(object me)
{
        message_vision(GRN"°aÁÕ¯P»¡¡R³o..³o...¤£¬O·íªì§Ú¦b¤s¤W©Ò¥Îªº¤¸®ð¥Û¶Ü¡H\n"NOR, me);
        message_vision(GRN"°aÁÕ¯Pºò´¤µÛ$Nªº¤â»¡¡GÁÂÁÂ§A¤F, "+ RANK_D->query_respect(this_player()) + ", ¬JµM§AÀ°¤F§Ú³o­Ó¦£, §Ú´N°e³o­Ó¤pÂ§µ¹§A§a¡I\n"NOR, me);
        return;
}

int accept_object(object me, object ob)
{
        if( !ob->id("open-war-stone") ) return 0;
        else if( me->query("class1") == "¯e­·ªù" && me->query("level") == 25 && !me->query("class2") && me->query_temp("got_stone") )
        {
                me->delete_temp("got_stone");
                me->set("class2", "¯e­·ªù");
                me->create_family("¯e­·ªù¶i¶¥", 3, "¼C¤h");
                me->set("guild_rank", WHT"¸g¦~¾ú½mªº·s¼C¤h"NOR);
                message_vision("$Nµ¹$n¤@" + ob->query("unit") + ob->name() + "¡C\n", me, this_object());
                me->set("adv_class", 2);
                me->set("guild_gifts",({ 4,6,5,5 }));
                message("world:world1:vision", WHT"¶W¯Å¤p±ø¡G"HIR" [ " + me->name(1) + " ¦¨¬°¤F°aÁÕ¯Pªù¤U¥¿¦¡ªº¼C¤h¤F¡I ] \n"NOR, users());
                write_file("/u/c/cominging/log/wind_adv.log" , sprintf("%s became the member of advenced wind party at %s\n", geteuid(me), ctime(time())));
                call_out("delay2", 1, me, ob);
                return 1;
        }
        else
        {
                message_vision("$Nµ¹$n¤@" + ob->query("unit") + ob->name() + "¡C\n", me, this_object());

                if( !me->query_temp("get_heal_stone") && !this_object()->query("give_heal_stone") )
                {
                        object stone = new(__DIR__"obj/heal_stone.c");
                        stone->move(me);
                        destruct(ob);
                        message_vision("$Nµ¹$n¤@" + stone->query("unit") + stone->name() + "¡C\n", this_object(), me);
                        me->set_temp("get_heal_stone", 1);
                        this_object()->set("give_heal_stone", 1);
                        call_out("delay3", 1, me);
                }
                else
                {
                        me->add("exp", 3000);
                        tell_object(me, "§A±o¨ì¤F 3000 ÂI¸gÅç¡C\n");
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
        if( this_player()->query("class2") != "¯e­·ªù" )
                return notify_fail("§A¤£¬O¯e­·¶i¶¥¼C¤h¡I\n");
        if( arg=="moon_force" 
        
                if( this_player()->query_skill( "moon_force", 1 ) == 0 
                return notify_fail("§A¨Ã¨S¦³´Ý¤ë¤ßªk°òÂ¦¡A¦]¦¹µLªk­×½m¡C\n")
        
        if( arg == "star-sword" 
        
        temp = this_player()->query_skill(arg) / 30
                if( this_player()->query("popularity") < temp 
                        return notify_fail("§A¦ü¥G¨S¦³¨¬°÷ªºÁn±æ¨Ó¦V" + this_object()->name(1) + "»â±Ð©ù¬P¼Cªk¡I\n")
        
        return GUILDMASTER->do_skill_train(this_object(),this_player(),arg);
void train_skill_cost(object me, string skill
    int temp = (skill=="star-sword") ? me->query_skill(skill)/30 : 0
        me->add("popularity",-temp)
        return
int do_advance(string arg
        object me = this_player()
        int pop = me->query("popularity"), lev = me->query("level") - 21
        if( me->query("class2") != "¯e­·ªù" 
                return notify_fail("§A¤£¬O¯e­·¶i¶¥¼C¤h¡I\n")
        if( (( !arg || arg == "level" ) && pop < (lev*lev+1)) || ( pop < 3 ) 
                return notify_fail("§AªºÁn±æ¤£¨¬¥Î¥H¤É¯Å¡I\n")
       
        return GUILDMASTER->do_advance(this_object(), me, arg)
// advance ¦¨¥\«á GUILDMASTER ·|¦Û°Ê©I¥
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
        if ( sword > 80 && force > 99 && force > sword ) rank = HIW"¼C³N°ª¶Wªº¤º¥\\®v"NOR
    else if ( force > 80 && sword > 99 && sword > force ) rank = HIW"¤º¤O´ý«pªº¼C³N¤h"NOR
        else if ( force > 99 && sword > 99 ) rank = HIC"µn®p³y·¥"HIW"¥þ¯à¼C¤h"NOR
        else if ( force > 70 ) rank = WHT"¤º¥\\°ª©úªº¯e­·¤H"NOR
        els
        {       switch( lv 
                
                        case 0: rank = WHT"¸g¦~¾ú½mªº·s¼C¤h"NOR; break
                        case 1: rank = WHT"»á¦³¦W®ðªº¤p¼C¤h"NOR; break
                        case 2: rank = WHT"¥\\¤O¤£¤Zªº¼C³N®v"NOR; break
                        case 3: rank = WHT"¯e­·ªùªº¥X®v°ª®{"NOR; break
                        case 4: rank = HIW"Áa¾î¤Ñ¤U¤@¥N¼C¤h"NOR; break
                        default: rank = WHT"¯e­·¶i¶¥¤dÁè¦Ê·Ò"NOR
                
        
        return rank
void die(
        object ob
        if( !ob = query_temp("last_damage_from") 
                ob = this_player(1)
        if( !ob )
        
                ::die()
                return
        
        message("world:world1:vision", WHT"\n ¶W¯ÅÄê±ø¡G [ ¶Ç»D"HIW"¯e­·ªùªù¥D "HIY"°aÁÕ¯P "NOR WHT"¦b "HIR + ob->name(1) + " "NOR WHT"ªº¤â¤U¡AÃ`¤U¤F©R¤¤ªº³Ì«á¤@¤f®ð¡C ] \n\n"NOR, users())
        ob->add("popularity", 100000); //Án±
        ::die()
        return
