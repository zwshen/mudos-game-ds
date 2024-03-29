// chard.c
// #pragma save_binary
#include <race.h>
#include <ansi.h>

void create() {
    seteuid(getuid());
}
void setup_char(object ob)
{
    string race;
    mapping my;

    if ( !stringp(race = ob->query("race")) )
    {
        race = "human";
        ob->set("race", "human");
    }

    switch (race) //修正轉換, 增加相容性.
    {
    case "野獸":
        ob->set("race","beast");
        race="beast";
        break;
    case "機械人":
    case "機器人":
        ob->set("race","robot");
        race="robot";
        break;
    case "美達人":
        ob->set("race","meda");
        race="meda";
        break;
    case "人類":
        ob->set("race","human");
        race="human";
        break;
    case "仙派":
        ob->set("race","Celestial");
        race="Celestial";
        break;
    case "妖魔":
        ob->set("race","evil");
        race="evil";
        break;
    case "獸人":
        ob->set("race","ogre");
        race="ogre";
        break;
    case "虎人":
        ob->set("race","tiger");
        race="tiger";
        break;

    default :
        break;
    }
    if ( !find_object( RACE_D(race) ) && file_size( RACE_D(race)+".c" ) < 0 )
        error("[Chard.c] :沒有此種族設定檔 (/adm/daemons/race/" + race + ".c)\n");
    RACE_D(race)->setup_attribute(ob);
    my = ob->query_entire_dbase();

    if ( undefinedp(my["hp"]) ) my["hp"] = my["max_hp"];
    if ( undefinedp(my["mp"]) ) my["mp"] = my["max_mp"];
    if ( undefinedp(my["ap"]) ) my["ap"] = my["max_ap"];
    if ( !ob->query_max_encumbrance() )
        ob->set_max_encumbrance( BASE_ENCUMBRANCE_DEFAULT + my["str"] * 1350 + my["level"] * 1000);
    if ( !ob->query_max_capacity() )
        ob->set_max_capacity( BASE_CAPACITY_DEFAULT + my["con"]*2 +my["level"]*2 );

    if (!userp(ob)) //一般技能
    {
        ob->skill_setup(my["level"]);
    }

    ob->reset_action();
}


// 鼠來寶活動
// 2008 中元節活動
string GHOST_ACTIVITY_D = "/open/world1/tmr/game/2008_ghost/ghost_drop.c";

void check_activity(object killer, object victim, object corpse) {
    if ( !objectp(victim) || !objectp(killer) ) return;
        GHOST_ACTIVITY_D->create(corpse, victim->query("level") );
}


varargs object make_corpse(object victim, object killer)
{
    int i;
    object corpse, *inv;
    string killer_name,who_kill,corpse_name,corpse_id;

    if ( victim->is_ghost() )
    {
        inv = all_inventory(victim);
        inv->owner_is_killed(killer);
        inv -= ({ 0 });
//              i = sizeof(inv);
//              while(i--)
//              {
//                      if(inv[i]->query("no_drop"))
//                      inv[i]->move(environment(victim));
//              }
        return 0;
    }
    who_kill="";
    if (!killer)
    {
        if (!killer_name=victim->query_temp("temp/death_type"))
            killer_name="[死因不明] ";
    }
    else
    {
        who_kill="被"+killer->name()+"殺";
        killer_name="[被"+killer->name()+"所殺] ";
    }
    corpse = new(CORPSE_OB);
    if (corpse_name=victim->query("corpse_name"))
    {

        if (corpse_id=victim->query("corpse_id")) corpse->set_name( corpse_name, ({ corpse_id ,"corpse" }) );
        else corpse->set_name( corpse_name, ({ "corpse" }) );
    }
    else corpse->set_name( victim->query("name") + "的屍體", ({ "corpse" }) );

    corpse->set("long", victim->long()
                + "然而﹐" + gender_pronoun(victim->query("gender"))
                + "已經"+ who_kill +"死了﹐只剩下一具屍體靜靜地躺在這裡。\n");

    corpse->set("status_desc",killer_name);
    corpse->set("age", victim->query("age"));
    corpse->set("level", victim->query("level"));
    corpse->set("gender", victim->query("gender"));
    corpse->set("race", victim->query("race"));
    if (killer) corpse->set("killer_id", killer->query("id"));
    if (victim->query("volume") < 1) corpse->set("volume",1);
    else corpse->set("volume",victim->query("volume"));
    corpse->set("victim_name", victim->name(1));

    if (victim->query_weight() > 50000) corpse->set_weight( 50000 );
    else corpse->set_weight( victim->query_weight() );

    corpse->set_max_encumbrance( victim->query_max_encumbrance() );
    corpse->set_max_capacity( victim->query_max_capacity() );

    // Don't let wizard left illegal items in their corpses.
    if ( !wizardp(victim) || !userp(victim))
    {
        inv = all_inventory(victim);
        inv->owner_is_killed(killer);
        inv -= ({ 0 });
        i = sizeof(inv);
        while (i--)
        {
            if (!inv[i]->query("no_drop"))
            {
                if ( (string)inv[i]->query("equipped")=="worn" )
                {
                    inv[i]->move(corpse);
                    if ( !inv[i]->wear() ) inv[i]->move(environment(victim));
                }
                else
                {
                    //if(!inv[i]->query("no_drop"))
                    inv[i]->move(corpse);
                }
            }
        }
    }

    if ( !userp(victim)  && !victim->query("no_scroll")
            && victim->query("level") >= 5
            && ENHANCE_D->isDropScroll() )  {
        object sc;
        sc = ENHANCE_D->createScroll(victim->query("level"));
        sc->move(corpse);
        // 記錄在news paper 上 - tmr 2007/04/29
        RECORD_D->add_scroll_record(
            sprintf( "[%s] %s(%s)" + NOR "在%s(%s)" + NOR "身上找出一張 %s。\n" NOR,
                     ctime(time()), killer->query("name"), killer->query("id"),
                     victim->query("name"), victim->query("id"),
                     sc->query("name")
                   )
        );
    }
    
    // 活動
//       check_activity(killer, victim, corpse);
    // 將corpse移到死亡現場
    corpse->move(environment(victim));

    return corpse;
}


