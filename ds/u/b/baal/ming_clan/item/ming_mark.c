// À°·|«Hª«
// "level": ª±®a¦bÀ°·|¤¤ªºµ¥¯Å(1~?)
// 1: ±Ð®{
// 2: °ó­û 
// 3: Å@ªk 
// 4: °ó¥D(can enter box)
// 5: ¥ú©ú¸t¨Ï(can enter box)
// 6: À°¥D (2¦W)(can enter box)
//¥_ªù§j­·»¡¡R­·¹p*2 îî¿V*2 ¤Ñ¼Ï*1 «C¤ì*1
// "title": À°·|ÀY»Î
// "info1": ³Æ¥Î°Ï1 (¤À°ó¦WºÙ)
// "info2": ³Æ¥Î°Ï2
// "info3": ³Æ¥Î°Ï3
//

#include <ansi.h>
#include <armor.h>
#define CLUB_NAME "©ú±Ð"
#define CLUB_ID "ming"
#define CLUB_CHANNEL "ming"
#define CLUB_MARK "Plate of Holy Fire"
#define CLUB_ENTER_FILE "/open/world1/tmr/bagi/rift1"
#define CLUB_OUT_FILE "/open/world1/baal/ming_club/lighttop"
inherit FINGER;
private string *members_level = ({
        "±Ð®{", //0
        "°ó­û", //1
        "Å@ªk", //2
        "°ó¥D", //3
        "¥ú©ú¸t¨Ï", //4
        "À°¥D", //5
});
void create()
{
        set_name(HIR"¸t¢w¤õ¢w¥O"NOR,({"Plate of Holy Fire","plate","club_mark"}));
        set_weight(600);
        if( clonep() ) set_default_object(__FILE__);
        else
        {
                set("value",0);
                set("no_drop",1);
                set("no_sell",1);
                set("no_sac",1);
                set("unit","¥u");
                set("long",@LONG
³o¬O¥Îºë­è½m¦¨ªº¬õ¦â¥OµP¡A¤W­±³zµÛ¬õ¥ú¬O±Ð¤¤Âí±Ð¤§Ä_
¥Ñ©_¥©¦K¤H©Ò»s¡A¥u­n¥X¥Ü¥OµP¡A¤j¦¿«n¥_ºZ¦æµLªý(show plate)¡C
[Ãö©ó©ú±Ðªº¨ä¥L»¡©ú½Ð¥Î<help ming>«ü¥O¬d¸ß¡C]
LONG
                );
        }
        set("club_id",CLUB_ID);
        set("club",CLUB_NAME);
        set("sub_club",({"­·¹p°ó","îî¿V°ó","¤Ñ¼Ï°ó","«C¤ì°ó"}));
        set("club_max_level",sizeof(members_level)-1);
        set("armor_prop/shield", 1);
        setup();
}

int query_autoload() { return 1; } //save_item

void init()
{
 mapping info;
 int level;
 if(environment(this_object())!=this_player()) return;
 level=CLUB_D->check_member(CLUB_ID,getuid(this_player()));
 if(level==0)
 {
        if(wizardp(this_player()))
        {
                 info = ([
                 "level": wiz_level(this_player()),
                 "title": "©ú±Ð¯S¯ÅÅU°Ý  ",
                 "info1": "µL",
                 "info2": ctime(time()),
                 "info3": this_player()->name_id(1)
                 ]);
                 CLUB_D->add_member(CLUB_ID,getuid(this_player()),info);
        }
        else 
        {
                tell_object(this_player(),this_object()->name()+"¬ðµM±q§A¨­¤W­¸¥X¡Aº¥º¥®ø¥¢¦b»·¤è¡C\n");
                this_player()->delete("club");
                destruct(this_object());
                return;
        }
 }
 switch(level)
 {
  case 6:
                add_action("do_handover","handover");
                add_action("do_lockleave","lockleave");
                add_action("do_givepower","givepower");
                add_action("no_suicide","suicide"); //¨¾¤î¦Û±þ
                add_action("do_subleader","subleader");
                add_action("do_retire","retire");
  case 5:
                add_action("do_listmember","listmember");
  case 4:
                add_action("do_accept","accept");
                add_action("do_kickout","kickout");
  case 2:
                add_action("do_include","include");
                add_action("do_dismiss","dismiss");
  default:
                add_action("do_help","help");
                add_action("do_members","members");
                add_action("do_leaveclub","leaveclub");
                add_action("do_enter_club","lift");
 }
}

int do_enter_club(string arg)
{
        object env,me;
        if(arg!="ring") return 0;
        me=this_player();
        env=environment(me);
        if(!env) return 0;
        if(env->query("ming_club_enter"))
        {
                if(me->query_temp("killer")) return notify_fail("¤Ñ¤W¶Ç¨Ó¤@­Ó«Õ«ÕªºÁn­µ: §A, ¦]¬°§A­è­è±þ¤F¤H©Ò¥H¼È®É¤£¯à¶i¤JÀ°·|¡C\n");
        if(me->query_temp("invader")) return notify_fail("¤Ñ¤W¶Ç¨Ó¤@­Ó«Õ«ÕªºÁn­µ: ¦]¬°§A­è­è¶Ë¤F¤H, ©Ò¥H¼È®É¤£¯à¶i¤JÀ°·|¡C\n");
                message_vision("$N°ªÁ|$n¤j³Û¡G¡u·í¤µªZªL½Ö¤H¯à¤ñ¡A°ß§Ú©ú±Ð¿W¨B¦¿´ò¡C¡v\n",me,this_object());
                if(!me->can_move(CLUB_ENTER_FILE))
                {
                        message_vision("¥Ñ¥ú©ú³»¤W©ñ¤U¤@¥xÆl¨®±N§A¸ü¤W¥h¡C\n",me);
                        return 1;
                }
                else
                {
                        tell_room(env,me->name()+"§¤¤WÆl¨®¡A³Q¸ü¤F¤W¥h¡C\n",({ me }));
                        me->move(CLUB_ENTER_FILE);
                        tell_room(environment(me),me->name()+"½w½wªºµ¹Æl¨®¸ü¤F¤W¨Ó¡C\n",({ me }));
                        write("Æl¨®½w½wªº°±¦í¤F¡A§Aµo²{¦Û¤v¤w¸g¨Ó¨ì¤F¢w¥ú©ú³»¡C\n");
                        me->add_busy(1);
                        return 1;
                }
        }
        else if(env->query("ming_club_out"))
        {
                message_vision("$N°ªÁ|$nµÛ¸õ¤W¤FÆl¨®¡A³QÆl¨®¸ü¤F¤U¥h¡C\n",me,this_object());
                if(!me->can_move(CLUB_OUT_FILE))
                {
                        message_vision("Æl¨®½w½wªº³Q¦Q¤F¤W¥h¡A¥u¨£$N¤£ª¾©Ò±¹ªº§b¯¸¦b­ì¦a¡C\n",me);
                        return 1;
                }
                else
                {
                        tell_room(env,me->name()+"ÀHµÛÆl¨®¦V¤UÂ÷¶}¡C\n",({ me }));
                        me->move(CLUB_OUT_FILE);
                        tell_room(environment(me),me->name()+"³QÆl¨®¸ü¤F¤U¨Ó¡C\n",({ me }));
                        write("Æl¨®³Q¦Q¤F¤W¥h¡A§A¤S¦A«×½ñ¦b"+environment(me)->query("short")+"ªº¤g¦a¤W¡C\n");
                        me->add_busy(1);
                        return 1;
                }
        }
        else return notify_fail("§A±N"+this_object()->name()+"°ª°ªÁ|°_¤j³Û¡G¡u·í¤µªZªL½Ö¤H¯à¤ñ¡A°ß§Ú©ú±Ð¿W¨B¦¿´ò¡C¡v¡A¦ý¬O¤°»ò¨Æ±¡³£¨Sµo¥Í¡C\n");
}


int filter_members(object ppl,string *list)
{
        if( !environment(ppl) ) return 0;
        if( member_array(getuid(ppl),list)!=-1 ) return 1;
        return 0;
}

string show_level(object user)
{
 int level,rank;
 mapping info;
 string str;
 if(wizardp(user)) return "¡iºaÅA·|­û¡j©ú±Ð¯S¯ÅÅU°Ý    ";
 level=user->query("level");
 if(level>100)  str = "¡i????????¡j";
 else if(level<11)      str = "¡i²Ä "+chinese_number(level)+" ¯Å¡j";
 else if(level<21)      str = "¡i²Ä"+chinese_number(level)+"¯Å¡j";
 else if(level%10==0)   str = "¡i²Ä"+chinese_number(level)+"¯Å¡j";
 else str = "¡i"+chinese_number(level)+"¯Å¡j";
 info=CLUB_D->query_member_info(CLUB_ID,getuid(user));
 rank=info["level"];
 switch(rank)
 {
        case 5: str+="©ú±Ð±Ð¥D  "; break;
        case 4: str+="©ú±Ð¥ú©ú¸t¨Ï  "; break;
        case 3: str+="©ú±Ð"+info["info1"]+"°ó¥D    "; break;
        case 2: str+="©ú±Ð"+info["info1"]+"Å@ªk"; break;
        default: 
                if(info["info1"]!="µL")
                {
                        str+="©ú±Ð"+info["info1"]+"°ó­û  "; break;
                } else str+="©ú±Ð±Ð®{    ";
 }
 return str;
}

int sort_member(object ob1, object ob2)
{
        int lv1,lv2;
        lv1=CLUB_D->check_member(CLUB_ID,getuid(ob1));
        lv2=CLUB_D->check_member(CLUB_ID,getuid(ob2));
        if(lv1 == lv2) return (int)ob1->query("level") - (int)ob2->query("level");
        else return (lv1 - lv2);
}

int do_members(string arg)
{
        object *users,me;
        string str,*list;
        int i,ppl_cnt,idle;
        me=this_player();
//      list=CLUB_D->club_members(CLUB_ID);
//      users = filter_array( users(), "filter_members", this_object() ,list);
        users = CLUB_D->find_online_members(CLUB_ID);
        str = "¡· "+CLUB_NAME+": \n";
        str += "¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w\n";

        users = sort_array(users, "sort_member", this_object());

        ppl_cnt = 0;
        i = sizeof(users);
        while( i-- )
        {
                        // Skip those users in login limbo.
                        if(!me->visible(users[i]) && wizardp(users[i])) continue;
                        str = sprintf("%s%12s%-16s %s(%s)",
                                str,
                                show_level(users[i]),
                                RANK_D->query_level(users[i]),
                                users[i]->name(1),
                                users[i]->query("id"),
)
                        if(users[i]->query_temp("killer")) str+=HIR" [±þ¤H¥Ç]"NOR;
                        idle=query_idle(users[i]);
                        if(users[i]->query_temp("invis")) str+=HIB"(Áô§Î)"NOR;
                        if(users[i]->query_temp("hide")) str+=HBK"(¸úÂÃ)"NOR;
                        if(users[i]->query_temp("netdead")) str+=HIG"<Â_½u¤¤>"NOR;
                        if(idle>60) str +=sprintf(HIY" (µo§b%d¤ÀÄÁ)"NOR,idle/60);
                        str +=sprintf("\n"NOR);
                        ppl_cnt++;
        
        str += "¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w\n";
        str = sprintf("%s¥Ø«e¦@¦³ %d ¦ì¦¨­û¦b½u¤W.\n", str, ppl_cnt);
        this_player()->start_more(str);
        return 1;
}

int do_include(string arg)
{
        string sub;
        object ob,me;
        mapping me_info,ob_info;
        me=this_player();
       
        if(!arg) return notify_fail("include <¤H¦W>\n");
        else
                {        
                ob = present(arg, environment(me));
                if(!ob) return notify_fail("³o¸Ì¦³³o­Ó¤H¶Ü¡S\n");
                if(!userp(ob) || ob==me ) return notify_fail("³o¸Ì¦³³o­Ó¤H¶Ü¡S\n");
                me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
                ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
                if(sizeof(ob_info)
                {
                        if(me_info["level"] != 2 ) return notify_fail("¥u¦³°ó¥D¯à±N±Ú¤H¦¬¤J¤À°ó¡C\n");
                        if(!stringp(sub=me_info["info1"])) return notify_fail("¥u¦³°ó¥D¯à±N±Ú¤H¦¬¤J¤À°ó¡C\n");
                        if(ob_info["level"] != 1 || ob_info["info1"]!="µL";
                                return notify_fail("¥u¦³¤@¯ë±Ð®{¥i¥H¦¬¤J§Aªº¤À°ó¡C\n");
                        ob_info["info1"]=sub;
                        CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
                        message_vision("$N±N$n¦¬¤J"+sub+", ¨Ã©ç©ç$nªºªÓ»H»¡: ¤µ«á´N¬Ý§Aªºªí²{¤F¡C\n",me,ob);
                        ob->save();
                        return 1;
                }
                 else return notify_fail("¹ï¤è¨Ã¨S¦³¥[¤J"+CLUB_NAME+"¡C\n");
        }
        return 1;
}
int do_dismiss(string arg)
{
        string sub;
        object ob,me;
        mapping me_info,ob_info;
        me=this_player();
       
        if(!arg) return notify_fail("dismiss <¤H¦W>\n");
        else
        {
                ob = present(arg, environment(me));
                if(!ob) return notify_fail("³o¸Ì¦³³o­Ó¤H¶Ü¡S\n");
                if(!userp(ob) || ob==me ) return notify_fail("³o¸Ì¦³³o­Ó¤H¶Ü¡S\n");
                me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
                ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));         
                if(sizeof(ob_info)
                
                        if(!sub=me_info["info1"] || me_info["level"]!=2 ) return notify_fail("¥u¦³°ó¥D¯à§K°£¤À°ó¤U¦¨­ûÂ¾°È¡C\n");
                        if(ob_info["level"] != 1 ) return notify_fail("¹ï¤è¨Ã¤£ÄÝ©ó§AªººÞÁÒ¡C\n");
                        if(ob_info["info1"] != sub) return notify_fail("¹ï¤è¨Ã¤£ÄÝ©ó§AªººÞÁÒ¡C\n");
                        ob_info["info1"]="µL";
                        CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
                        message_vision("$N¸Ñ°£¤F$n¦b"+sub+"ªºÂ¾°È, ·n·nÀY»¡: ¤S¤Ö¤F¤@­Ó¤H¤~...¯u¬O¥i±¤°Ú¡C\n",me,ob);
                        ob->save();
                        return 1;
                }
                 else return notify_fail("¹ï¤è¨Ã¨S¦³¥[¤J"+CLUB_NAME+"¡C\n");
}
        return 1;
                        }
//¦¬¤H
int do_accept(string arg)
{
        string *clubs;
        object ob,mark,me;
        mapping info;
        me=this_player();
        if(!arg) return notify_fail("§A­nÅý½Ö¥[¤J"+CLUB_NAME+"¡S\n");
        else
        {
                ob = present(arg, environment(me));
                if (!ob) return notify_fail("³o¸Ì¦³³o­Ó¤H¶Ü¡S\n");
                if(!userp(ob) || ob==me ) return notify_fail("³o¸Ì¦³³o­Ó¤H¶Ü¡S\n");
                if(ob->query_temp("joinclub") != me->query("id") )
                {
                        return notify_fail("¹ï¤è¨Ã¨S¦³¦V§A¥Ó½Ð¤JÀ°(joinclub).\n");
                }
                clubs=CLUB_D->find_player_club(getuid(ob));
                if(sizeof(clubs)>0)
                {
                        if(clubs[0]==CLUB_ID) return notify_fail("¹ï¤è¤w¸g¬O"+CLUB_NAME+"ªº¤@¥÷¤l¤F¡C\n");
                        else return notify_fail("¹ï¤è¤w¸g¥[¤J¤F§OªºÀ°¬£¡C\n");
                }
                 else
                {
                 mark=new(base_name(this_object()));
                 if(!mark) return notify_fail("À°·|«Hª«¨ú±o¥¢±Ñ¡C\n");
                 if( !mark->can_move(ob) ) return notify_fail(ob->name(1)+"®³¤£°Ê"+mark->query("name")+"¡C\n");
                 message_vision("$Nµ¹¤F$n¤@"+mark->query("unit")+mark->query("name")+", ¨Ã¶©­«ªºªï±µ$n¦¨¬°"+CLUB_NAME+"ªº¤@¥÷¤l¡C\n",me,ob);
                 info = ([
                 "level": 1,
                 "title": "©ú±Ð±Ð®{",
                 "info1": "µL",
                 "info2": ctime(time()),
                 "info3": me->name_id(1)
                 ]);
                 CLUB_D->add_member(CLUB_ID,getuid(ob),info);
                 mark->move(ob);
                 ob->add("channels", ({"ming"}));
                 ob->save();
                }
        }       
        return 1;
}

int do_kickout(string arg)
{
        string *tuned_ch;
        object ob,mark,me;
        mapping me_info,ob_info;
        me=this_player();
        
        if(!arg) return notify_fail("§A­n±N½Ö½ð¥X"+CLUB_NAME+"¡S\n");
        else
        {
               ob = present(arg, environment(me));
                if (!ob)
                {
                        if(!CLUB_D->is_club_leader(me)) return notify_fail("³o¸Ì¦³³o­Ó¤H¶Ü¡S\n");
                        else {
                                write("[Â÷½u¶}°£]:");
                                if(ob=find_player(arg)) return notify_fail("¹ï¤èÁÙ¦b½u¤W¡C\n");
                                if( CLUB_D->remove_member(CLUB_ID,arg) )
                                {
                                        write("¦¨¥\\¶}°£¤F"+arg+"¡C\n");
                                        return 1;
                                }
                                else return 0;
                        }
                }
                if(!userp(ob) || ob==me ) return notify_fail("³o¸Ì¦³³o­Ó¤H¶Ü¡S\n");
                
                me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
                ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));  
                
                if(sizeof(ob_info))
                {
                        if(ob_info["level"] >= me_info["level"])
                                return notify_fail("§A¤£°÷¸ê®æ±N¹ï¤è½ð¥X"+CLUB_NAME+"¡C\n");
                        if( wiz_level(ob) > wiz_level(me) && wizardp(ob))
                                return notify_fail("§A¤£°÷¸ê®æ±N¹ï¤è½ð¥X"+CLUB_NAME+"¡C\n");
                        tuned_ch = ob->query("channels");
                        if( pointerp(tuned_ch) && member_array(CLUB_CHANNEL, tuned_ch)!=-1 )
                        {
                                tuned_ch -= ({ CLUB_CHANNEL });
                                ob->set("channels", tuned_ch);
                        }
                        //ob->delete("club");
                        if(!mark=present(CLUB_MARK,ob))
                        {
                                write("À°·|«Hª«¨ú±o¥¢±Ñ¡C\n");
                        }
                        else
                        {
                                message_vision("$N¨S¦¬¤F$nªº"+mark->query("name")+", ¨Ã±j¨î$n°h¥X"+CLUB_NAME+"¡C\n",me,ob);
                                destruct(mark);
                        }
                        CLUB_D->remove_member(CLUB_ID,getuid(ob));
                        ob->save();
                        return 1;
                }
                 else return notify_fail("¹ï¤è¨Ã¨S¦³¥[¤J"+CLUB_NAME+"¡C\n");
        }
        return 1;
}

int do_subleader(string arg)
{
        string id,sub;
        object ob,me,mark;
        mapping me_info,ob_info;
        me=this_player();
        
        if(!arg) return notify_fail("subleader <¤H¦W> to <¤À°ó¦W>\n");
        else
        {
                if( sscanf(arg, "%s to %s", id, sub)!=2 ) return notify_fail("subleader <¤H¦W> to <¤À°ó¦W>\n");
                ob = present(id, environment(me));
                if(!ob) return notify_fail("³o¸Ì¦³³o­Ó¤H¶Ü¡S\n");
                if(!userp(ob) || ob==me ) return notify_fail("³o¸Ì¦³³o­Ó¤H¶Ü¡S\n");

                me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
                ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));  
                
                if(sizeof(ob_info))
                {
                        if(ob_info["level"] != 1)
                                return notify_fail("¥u¦³¤@¯ë°ó²³¥i¥H¦¨¬°°ó¥D¡C\n");
                        if( (int) member_array(sub, query("sub_club"))<0 )
                                return notify_fail("¥Ø«e¥i¥Îªº¤ÀºX¬°¡i­·¹p°ó¡j¡B¡iîî¿V°ó¡j¡B¡i¤Ñ¼Ï°ó¡j¡B¡i«C¤ì°ó¡j¡C\n");
                        ob_info["level"]=2;
                        ob_info["info1"]=sub;
                        CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
                        if(!mark=present(CLUB_MARK,ob))
                        {
                                write("À°·|«Hª«¨ú±o¥¢±Ñ¡C\n");
                        }
                        else
                        {
                                message_vision("$N±N$n´£ª@¬°"+sub+"°ó¥D, ¨Ã©M$n´¤¤â«jÀy¤@µf¡C\n",me,ob);
                                mark->move(ob);
                        }
                        ob->save();
                        return 1;
                }
                 else return notify_fail("¹ï¤è¨Ã¨S¦³¥[¤J"+CLUB_NAME+"¡C\n");
        }
        return 1;
}

int do_retire(string arg)
{
        string sub;
        object ob,me,mark;
        mapping me_info,ob_info;
        me=this_player();
        
        if(!arg) return notify_fail("retire <¤H¦W> \n");
        else
        {
                ob = present(arg, environment(me));
                if(!ob) return notify_fail("³o¸Ì¦³³o­Ó¤H¶Ü¡S\n");
                if(!userp(ob) || ob==me) return notify_fail("³o¸Ì¦³³o­Ó¤H¶Ü¡S\n");

                me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
                ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));

                if(sizeof(ob_info))
                {
                        if(ob_info["level"] != 2) return notify_fail("¹ï¶H¨Ã¤£¬O°ó¥D¡C\n");
                        sub=ob_info["info1"];

                        ob_info["level"]=1;
                        ob_info["info1"]="µL";
                        CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);

                        if(!mark=present(CLUB_MARK,ob))
                        {
                                write("À°·|«Hª«¨ú±o¥¢±Ñ¡C\n");
                        }
                        else
                        {
                                message_vision("$N§K°£¤F$nªº"+sub+"°ó¥DÂ¾°È¡C\n",me,ob);
                                mark->move(ob);
                        }
                        ob->save();
                        return 1;
                }
                 else return notify_fail("¹ï¤è¨Ã¨S¦³¥[¤J"+CLUB_NAME+"¡C\n");
        }
        return 1;
}

int do_givepower(string arg)
{
        string id,type,res;
        int level;
        object ob,me,mark;
        mapping me_info,ob_info;
        me=this_player();
        
        if(!arg) return notify_fail("givepower <¤H¦W> to <µ¥¯Å>\n");
        else
        {
                if( sscanf(arg, "%s to %d", id, level)!=2 ) return notify_fail("givepower <¤H¦W> to <µ¥¯Å>\n");
                ob = present(id, environment(me));
                if(!ob) return notify_fail("³o¸Ì¦³³o­Ó¤H¶Ü¡S\n");
                if(!userp(ob) || ob==me) return notify_fail("³o¸Ì¦³³o­Ó¤H¶Ü¡S\n");

                me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
                ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
                
                if(sizeof(ob_info))
                {
                        if(ob_info["level"] >= me_info["level"]) return notify_fail("§A¨S¦³¸ê®æ§ïÅÜ¹ï¤èªºÂ¾°Èµ¥¯Å¡C\n");
                        if( wiz_level(ob) > wiz_level(me) && wizardp(ob)
                                        return notify_fail("§A¨S¦³¸ê®æ§ïÅÜ¹ï¤èªºÂ¾°Èµ¥¯Å¡C\n");
                        if(level >= me_info["level"]
                                return notify_fail("§A¨S¦³¸ê®æ´£ª@¹ï¤èªºÂ¾°Èµ¥¯Å¨ì³o­Óµ¥¯Å¡C\n");
                        if(level == ob_info["level"]
                                return notify_fail("¹ï¤è¤w¸g¬O"+(string)members_level[level]+"¤F¡C\n");
                        if(level > 5 || level < 1 
                                return notify_fail("¥Ø«eµ¥¯Å¤À¬° <1:±Ð®{> <2:°ó­û> <3:Å@ªk> <4:°ó¥D> <5:¥ú©ú¸t¨Ï><6:±Ð¥D> \n");
                        if( level > ob_info["level"] 
                        {
                                type="´£ª@";
                                res ="¨Ã©M$n´¤¤â«jÀy¤@µf";
                        }
                        else
                        {
                                type = "­°";
                                res ="¨Ã©ç©ç$nªºªÓ»H´Á«j$n¯à±N¥\\§é¸o";
                        }
                        switch(level)
                        {
                                case 1;
                                        ob_info["level"]=1;
                                        ob_info["info1"]="µL";
                                        ob_info["info2"]=ctime(time());
                                        ob_info["info3"]=me->name_id(1);
                                        break;
                                case 2;
                                        return notify_fail("½Ð¥Îsubleader«ü¥O¨Ó«ü©w¤@­Ó¤ÀºX¡C\n");
                                        break;
                                case 3;
                                        ob_info["level"]=3;
                                        ob_info["info1"]="µL";
                                        ob_info["info2"]=ctime(time());
                                        ob_info["info3"]=me->name_id(1);
                                        break;
                                case 4;
                                        ob_info["level"]=4;
                                        ob_info["info1"]="µL";
                                        ob_info["info2"]=ctime(time());
                                        ob_info["info3"]=me->name_id(1);
                                        break;
                                case 5;
                                        return notify_fail("½Ð¥Îhandover«ü¥O°µ«ü´§Åv²¾¥æ¡C\n");
                                        break;
                                default: return notify_fail("°Ñ¼Æ¿ù»~¡C\n");
                                                }
                        
                        CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
                        if(!mark=present(CLUB_MARK,ob))
                        {
                                write("À°·|«Hª«¨ú±o¥¢±Ñ¡C\n");
                        }
                        else
                        {
                                message_vision("$N±N$nªºÂ¾¦ìµ¥¯Å"+type+"¬°"+(string)members_level[level]+"(µ¥¯Å"+(string)level+"), "+res+"¡C\n",me,ob);
                                mark->move(ob);
                        }
                        ob->save();
                        return 1;
                }
                 else return notify_fail("¹ï¤è¨Ã¨S¦³¥[¤J"+CLUB_NAME+"¡C\n");
        }
        return 1;
}
int do_handover(string arg)
        object ob,mark,me;
        mapping me_info,ob_info;
        me=this_player();
        if(!arg) return notify_fail("§A­n±N¤jÅv²¾¥æµ¹½Ö¡S\n");
        else
        {
                ob = present(arg, environment(me));
                if (!ob) return notify_fail("³o¸Ì¦³³o­Ó¤H¶Ü¡S\n");
                if(!userp(ob) || ob==me) return notify_fail("³o¸Ì¦³³o­Ó¤H¶Ü¡S\n");
               
                if(CLUB_D->query_club_leader(CLUB_ID)!=getuid(me)) return notify_fail("§A¤£¬O¯u¥¿ªºÀ°·|»â¾É¤H¡C\n");
              
                me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
                ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
                if(sizeof(ob_info))
                {
                        CLUB_D->set_club_leader(CLUB_ID,getuid(ob));
                       
                        ob_info["level"]=5;
                        ob_info["info1"]="µL";
                        ob_info["info2"]=ctime(time());
                        ob_info["info3"]=me->name_id(1);
                        CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
                       
                        me_info["level"]=3;
                        me_info["info1"]="µL";
                        me_info["info2"]=ctime(time());
                        me_info["info3"]=me->name_id(1);
                        CLUB_D->set_member(CLUB_ID,getuid(me),me_info);
                        
                        mark=present(CLUB_MARK, me);
                        if(!mark)
                        {
                                write("À°·|«Hª«¨ú±o¥¢±Ñ¡C\n");
                        }
                        else
                        {
                                mark->move(me);
                        }
                        mark=present(CLUB_MARK, ob);
                        if(!mark)
                        {
                                write("À°·|«Hª«¨ú±o¥¢±Ñ¡C\n");
                        }
                        else
                        {
                                mark->move(ob);
                        }
                        message_vision("$N±N"+CLUB_NAME+"ªºÁ`«ü´§Åv²¾¥æµ¹$n¡C\n",me,ob);
                        message( "channel:ming",YEL"¡i"+CLUB_NAME+"¡j"+me->name(1)+"("+capitalize(me->query("id"))+")±N"+CLUB_NAME+"«ü´§Åv²¾¥æµ¹"+ob->name(1)+"("+capitalize(ob->query("id"))+")¡C\n"NOR, users() );
                        ob->save();
                        me->save();
                        return 1;
                }
                 else return notify_fail("¹ï¤è¨Ã¤£¬O"+CLUB_NAME+"ªº¤@¥÷¤l¡C\n");
        }
        return 1;
}

int do_leaveclub(string arg)
{
        string *tuned_ch;
        object mark,me;
        me=this_player();
        
        if(CLUB_D->query_club_leader(CLUB_ID)==getuid(me))
                return notify_fail("§A¥²¶·¥ý±N¤jÅvÂà²¾¤~¯àÂ÷¶}"+CLUB_NAME+"¡C\n");
        CLUB_D->remove_member(CLUB_ID,getuid(me));
        message_vision("$N¥D°Ê°h¥X¤F"+CLUB_NAME+"¡C\n",me);
        message( "channel:ming",YEL"¡i"+CLUB_NAME+"¡j"+me->name(1)+"("+capitalize(me->query("id"))+")¥D°Ê°h¥X¤F"+CLUB_NAME+"¡C\n"NOR, users() );
        tuned_ch = me->query("channels");
        if( pointerp(tuned_ch) && member_array(CLUB_CHANNEL, tuned_ch)!=-1 );
        {
                        tuned_ch -= ({ CLUB_CHANNEL });
                        me->set("channels", tuned_ch);
        }
        me->delete("club");
        if(!mark=present(CLUB_MARK,me))
        {
                write("À°·|«Hª«¨ú±o¥¢±Ñ¡C\n");
        } else destruct(mark);
        me->save();
        return 1;
}
int do_lockleave(string arg)
{
        if(CLUB_D->query_club_leader(CLUB_ID)!=getuid(this_player())) return notify_fail("§A¤£¬O¯u¥¿ªºÀ°·|»â¾É¤H¡C\n");
        if(arg=="on")
        {
                if(CLUB_D->query_lockleave(CLUB_ID)==1) return notify_fail("°hÀ°­­¨î¤w¸g¶}±Ò¡C\n");
                CLUB_D->set_lockleave(CLUB_ID,1);
                write("§A±N"+CLUB_NAME+"³]©w¬°¤£¥i°hÀ°¡C\n");
                return 1;
        }
        if(arg=="off")
        {
                if(CLUB_D->query_lockleave(CLUB_ID)==0) return notify_fail("°hÀ°­­¨î¤w¸gÃö³¬¡C\n");
                CLUB_D->set_lockleave(CLUB_ID,0);
                write("§A±N"+CLUB_NAME+"³]©w¬°¥i¥H°hÀ°¡C\n");
                return 1;
        }
        return notify_fail("lockleave <on/off> \n");
}
int no_suicide(string arg)
{
        if(CLUB_D->query_club_leader(CLUB_ID)==getuid(this_player()))
        {
                write("¨­¬°"+CLUB_NAME+"°ª¯Åªø©x, ¥æ¥X«ü´§Åv¤§«e¤£¥i»´¥Í, ¥H§K«áÄ~µL¤H¡C\n");
                return 1;
        }
        return 0;
}

int do_listmember(string arg)
{
        string *list,*members,temp,output;
        int i,j;
        mapping club;
        list=CLUB_D->club_members(CLUB_ID);
        club=CLUB_D->query_club_record(CLUB_ID);
        members=keys(club);
        output="\n¥Ø«e"+CLUB_NAME+"µn°O¦³®×ªº¦¨­û¦³:\n";
        if(arg=="long")
        {
                for(i=this_object()->query("club_max_level");i>0;i--)
                {
                        for(j=0;j<sizeof(members);j++)
                        {
                                if(club[members[j]]["level"]==i) output=sprintf("%s %12s À°·|µ¥¯Å: %d\n",output,members[j],i);
                        }
                }
                output=sprintf("%s \n¥Ø«e%s¦@­p¦³: %d ¦W¦¨­û¡C\n",output,CLUB_NAME,sizeof(members));
                write(output);
                return 1;
        }
        temp=CLUB_D->query_club_leader(CLUB_ID);
        output=sprintf("%s »â¾É¤H: %12s\n",output,temp);
        list-=({temp});
        output=sprintf("%s ¨ä¥L:\n",output,temp);
        output+=CLUB_D->show_club_members(CLUB_ID);
        output=sprintf("%s¥Ø«e%s¦@­p¦³: %d ¦W¦¨­û¡C\n",output,CLUB_NAME,sizeof(members));
        write(output);
        return 1;
}

int do_help(string arg)
{
 if(arg=="ming")
 {
  write(@HELP

       ùæùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùè
       ¢x                      À°·|«Hª«ªº»²§U»¡©ú                        ¢x
       ¢u¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢s¢w¢w¢w¢w¢w¢w¢w¢w¢w¢s¢w¢w¢w¢w¢w¢w¢t
       ¢x  «ü¥O®æ¦¡                    ¢x»¡©ú              ¢xÅv­­        ¢x
       ¢u¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢q¢w¢w¢w¢w¢w¢w¢w¢w¢w¢q¢w¢w¢w¢w¢w¢w¢t
       ¢x  help ming                   ¢x¥»»²§U°T®§        ¢x±Ú¤H        ¢x
       ¢x  ming <§Aªº°T®§>             ¢xÀ°·|±M¥ÎÀW¹D      ¢x±Ú¤H        ¢x
       ¢x  members                     ¢x¦C¥X½u¤WÀ°·|¦¨­û  ¢x±Ú¤H        ¢x
       ¢x  leaveclub                   ¢x¥D°Ê°h¥XÀ°·|      ¢x±Ú¤H        ¢x
       ¢x  include <¤H¦W>              ¢x±N¬Y¤H¦¬¤J¤ÀºX    ¢xºX¥D±M¥Î    ¢x
       ¢x  dismiss <¤H¦W>              ¢x¨ú®ø¬Y¤H¤ÀºXÂ¾°È  ¢xºX¥D±M¥Î    ¢x
       ¢x  accept <¤H¦W>               ¢xÅý¬Y¤H¥[¤JÀ°·|    ¢xªø¦Ñ¥H¤W    ¢x
       ¢x  kickout <¤H¦W>              ¢x±N¬Y¤H³v¥XÀ°·|    ¢xªø¦Ñ¥H¤W    ¢x
       ¢x  lockleave <on> <off>        ¢x­­¨î¦Û¦æ°hÀ°      ¢x±Úªø        ¢x
       ¢x  subleader <¤H¦W> to <¤À°ó¦W>¢x¤É¯Å¬Y¤H¬°ºX¥D    ¢x±Úªø        ¢x
       ¢x  retire <¤H¦W>               ¢xºM°£¬Y¤HºX¥DÂ¾¦ì  ¢x±Úªø        ¢x
       ¢x  givepower <¤H¦W> to <µ¥¯Å>  ¢x§ïÅÜ¬Y¤HªºÂ¾¦ì    ¢x±Úªø        ¢x
       ¢x  handover <¤H¦W>             ¢x´xªùÂ¾°È¥æ±µ      ¢x±Úªø        ¢x
       ¢x  listmember                  ¢xÀ°·|¦W¥U          ¢xªø¦Ñ¥H¤W    ¢x
       ¢|¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢w¢r¢w¢w¢w¢w¢w¢w¢w¢w¢w¢r¢w¢w¢w¢w¢w¢w¢}
         ¡· ¨Ï¥Î accept «ü¥O¥²¶·¹ï¤è¥ý¥Î joinclub «ü¥O¥Ó½Ð¤~¯à¥Í®Ä¡C
         ¡· ©ú±Ð¥Ø«e¦³¥|­Ó¤À°ó:¡i­·¹p°ó¡j¡B¡iîî¿V°ó¡j¡B¡i¤Ñ¼Ï°ó¡j¡B¡i«C¤ì°ó¡j¡C
         ¡· µ¥¯Å¤À¬°: <1:±Ð®{> <2:°ó­û> <3:Å@ªk> <4:°ó¥D> <5:¥ú©ú¸t¨Ï><6:±Ð¥D> ¡C
         ¡· ¨ä¥L©ú±Ðªº¨Æ°È: <help ming_rule> , <help ming_group> ¡C
        
HELP
  );
  return 1;
  }
  if(arg=="ming_rule")
  {
   this_player()->start_more(@RULE

       CCKK,RICHANµ¥¤H©|¥¼´£¨Ñ,¥¼«Ø¥ß
                       
                             BAAL@DS

RULE
);
return 1;
  }
  if(arg=="ming_group")
  {
  this_player()->start_more(@MING_PART

    ¦b·É¿¤ªº¯e­·ªù¤º¡A¤@¸s¤H¥¿½mµÛ¼C¡A·í¤@¤H¨­ªk¿ð¶w¡A¼C
»R¥F¤O¡A¦b¤j®a¥ð®§®É¥LÁÙ§V¤Oªº½mµÛ¼C¡A®ÇÃäªº¶¥±è¤W¯¸µÛ¤@
¬°¤¤¦~¨k¤l¡A¦V¥L©Û¤F©Û¤â¡A¨â¤H¨«¨ì«á°|¡A·¨Âù«E´£¼C¹B®ð¨Ï
¥X¯Á·¥¼Cªk»P°g¤Û¤C¨B³Z¡A¥u¨£¥Õ¥ú°{°{¡A¨­¼vÄÆ´ù¡A¬ðµM·¨Âù
«E­¸¨­¦Ó°_¡A¦V¤@®Çªº¤j¾ð¬å¥h¡A¥u¨£¤j¾ð¤@¤À¬°¤G¡C¥L¸÷¤U¨Ó
µh­ú¤j³Û¡G¡u¬°¤°»ò¡H¡I¬°¤°»ò¡H¡I§Ú¬°¤°»ò¾Ç¤£·|¡H¡C¡v·¨Âù
«E©ç©ç¥L»¡¡G¡u¤£­n¦Ç¤ß....¡I¡v¥L¯¸°_¨Ó°í¨Mªº»¡¡G¡u§Ú­nÂ÷
¶}³o¸Ì¡I¡v
      ¤Q      ¦~      «á   ¡E  ¡E  ¡E  ¡E  ¡E  ¡E
    ¤@¦ì«C¦~¯¸¦b¤Ñ¦Àªº¤j¥Û¤W¡A½L»L­×½m´Ý¤ë¤ßªk¡A¥LÂù²´±i
¶}¡A¥k¤â¤@´§¡A¼CÀH¤Î¦Ó¥X¡A¥LÁa¨­¤W¼C±s¼C¦Ó¥h¡C­ì¨Ó¥L¦b¤Q
¦~¤¤¨«¹M¤Ñ¤U¡A´M³X¦W®v¡A½m¦¨¤@¨­¥»»â¡A²{«ô°aÁÕ¯Pªù¤U¡C
    
    ¦b©s§øªº¤K·¥ªù¤º¡A¤@¸s§ø¤H¥¿½mµÛ®±¡A¤§¤¤¤@¦ì¤p¨k«Ä¥´
°_®±¨Óªêªê¥Í­·¡A¤@ÂI¤]¤£¿éµ¹¤j¤H¡A¥ÛªO«Îªù¤f¯¸µÛ´N¬O¦W¾_
¦¿´òªº§õ®Ñ¤å¡C§õ®Ñ¤å¬Ý¤F¤§«á¡A·t¦Û¤U©w­n§â¥þ¨­µ´¾Ç¶Çµ¹¥L
¡C¥L¤Ñ¤Ñ½m®±±q¤£¾Ó«å¡A´X¦~ªº¥\¤Ò´N¦¨¤F§õ®Ñ¤åªº±o·Nªù¥Í¡A
¤@¤Ñ¥L¨ì«á¤s¥h½m®±¡AµL·N¶¡µo²{¤s¾À¶¡¦³¤@±ø»ØÁ_¡A¥L¦n©_ªº
Æp¤F¶i¥h¡A¨S·Q¨ì¸Ì­±§O¦³¬}¤Ñ¡A­ì¨Ó¬O®y¤s¨¦¡A¥L¦b¸Ì­±¹J¨£
¤@°¦¥Õ¤ò¤j·á¡A©M¨e¦¨¬°¦nªB¤Í¡A¤Ñ¤Ñ»P¨e½m®±¡A¥\¤O³ºµM¬ð­¸
²r¶i¡A´X¦~«áªº¤@ÂI¡A§õ®Ñ¤å§â¥L¥s¶i¨Ó»¡¡G¡u«Ä¤l¡A§Ú¨S¤°»ò
¥i¥H±Ð§A¤F¡A¬O¸ÓÅý§A¨«¤F¡C¡v¥L«ô§O§õ®Ñ¤å¥X¥hÂô¿º¦¿´ò¡C
      ¼Æ      ¦~      «á   ¡E  ¡E  ¡E  ¡E  ¡E  ¡E
    ¤@¦ì«C¦~»Eºë·|¯«¨nµÛ§N¤ëÃ~¡A§N¤ëÃ~ÅS¥X¤ë¤ú¡A¦å¬õªºÂù
²´«ãµøµÛ¥L¡A§N¤ëÃ~¨­¤Wªº¶Ë¤f¤£Â_ªº«_¥XÂA¦å¡A¤ë¤ú¤]¦]¦å¦Ó
¬V¬õ¡A§N¤ëÃ~·Ç³Æµo¥X­P©R¤@À»¡A§N¤ëÃ~½Ä¦V«C¦~¡A«C¦~Âù¤â¤Ï
¦©¦í§N¤ëÃ~¡AÂ½¨­¦V§N¤ëÃ~µo¥X¡u²rªêµwª¦¤s¡v¡A§N¤ëÃ~¦R¤F´X
¤fÂA¦å¦Ó¤`¡C¥LÂ÷¶}¤§«á¡A¸I¥©¹J¨£§dÄÁ¡A§dÄÁ¨£¥L¤Ñ¸êÁo±Ó
´N¦¬¥L¬°®{¡A¥L²{¦b´N¬OªZªL¤¤ÅT¥m¾´ªº¤Hª«  ------Richa
    ¦h¦~«eªº¤@­Ó©]±ß¡A¨â¤H¦]¬°Á¿¸Ü«Ü§ë¾÷¦Óµ²«ô¦¨¥S§Ì¡A¤
©w¨M¤ß­n¦¨¥ß¡i©ú±Ð¡j¡A©ó¬O¨â¤H¶}©lºôÃ¹¤H¤~¡A¤]¦]³o¨Ç³ÐÀ
ªº¤H¤~¡A©M¤Ñ¦a·|ªº°ö¾i¡A¤~¦³¡i©ú±Ð¡j¡C³o¤Ñ³o¤@¸s¥¿¦b¬°À

·|­n³]¦b¨º¦Ó¶Ë¸£µ¬¡A¬ðµMRichan»¡­n±a¤j®a¥h¤@­Ó¦a¤è¡A¤j¥
¨Ó¨ì¥Õ¤ò¤j·áªº¤s¨¦¡A¬Ý¨ì¤@­±Äa±V¡A²³¤H¨Ï¥X¤W­¼»´¥\¦V¤WÅ
¥h¡A¥u¨£±V³»¡A¤@¤ù¥ú«G¡A¦V¥~±æ¥h¸U¨½µL¶³¡A©ó¬O©R¦W¬°¡u¥
©ú³»¡v¡A¤j®a¬Ý¤F¬Ý¥|©P¡AÄ±±o¦n¹³¤Ö¤F¤°»ò¡A Ccr¤£ª¾¥h¨º·
¤@¶ô¤d¤ç¥Û¡ARichan´£°_µµª÷ºjÅD¦V¥¨¥Û´£¹D¡G¡u·í¤µªZªL½Ö¤
¯à¤ñ¡A°ß§Ú©ú±Ð¿W¨B¦¿´ò¡C¡v¤j®a§V¤O±oÁÈ¿ú¥[¤WBaal©MLukyª
¨ó§U²×©ó¦¨¥ß¤µ¤Ñªº©ú±Ð¡
                                       Richan@DS
ming_PART
);
  return 1;    
  }
 return 0;
}       

