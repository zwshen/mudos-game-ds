// score.c
#include <ansi2.h>
#include <combat.h>

#define WAR_SCORE_BAR  "                                                                     "

inherit F_CLEAN_UP;
string attribute_color(int current, int value);
string attitude_report(int evil_value);
string status_color(int current, int max);
string query_element_chinese(string elm);
void create() {
    seteuid(ROOT_UID);
}

string getWarScoreBar(int war_score) {
    int len, max;
    string result;
    len = strlen(WAR_SCORE_BAR);
    max = 10000;
    result =  sprintf(HBGRN"%s"HBBLU"%s"NOR,
                      WAR_SCORE_BAR[0..(len*war_score/max)] + NOR,
                      WAR_SCORE_BAR[ (len*war_score/max)+1..(len-1)]);
    return result + "%5.2f％";
}

// uncolor() add by -Acme-
string uncolor(string msg)
{
    if ( !msg ) return 0;
    msg = replace_string(msg, BLK, "");
    msg = replace_string(msg, RED, "");
    msg = replace_string(msg, GRN, "");
    msg = replace_string(msg, YEL, "");
    msg = replace_string(msg, BLU, "");
    msg = replace_string(msg, MAG, "");
    msg = replace_string(msg, CYN, "");
    msg = replace_string(msg, WHT, "");
    msg = replace_string(msg, HBK, "");
    msg = replace_string(msg, HIR, "");
    msg = replace_string(msg, HIG, "");
    msg = replace_string(msg, HIY, "");
    msg = replace_string(msg, HIB, "");
    msg = replace_string(msg, HIM, "");
    msg = replace_string(msg, HIC, "");
    msg = replace_string(msg, HIW, "");

    msg = replace_string(msg, BBLK, "");
    msg = replace_string(msg, BRED, "");
    msg = replace_string(msg, BGRN, "");
    msg = replace_string(msg, BYEL, "");
    msg = replace_string(msg, BBLU, "");
    msg = replace_string(msg, BMAG, "");
    msg = replace_string(msg, BCYN, "");

    msg = replace_string(msg, HBRED, "");
    msg = replace_string(msg, HBGRN, "");
    msg = replace_string(msg, HBYEL, "");
    msg = replace_string(msg, HBBLU, "");
    msg = replace_string(msg, HBMAG, "");
    msg = replace_string(msg, HBCYN, "");
    msg = replace_string(msg, HBWHT, "");

    msg = replace_string(msg, NOR, "");
    msg = replace_string(msg, U, "");
    msg = replace_string(msg, BLINK, "");
    msg = replace_string(msg, REV, "");

    return msg;
}

// getConditionBuffer() add by -Acme-
string getConditionBuffer(object ob) {
    int cnt;
    string tmp, msg, buf, sk;
    mapping buffering;

    buffering = ob->query_conditions();

    msg = "";
    cnt = 0;
    if ( sizeof(buffering) ) {
        foreach(buf in keys(buffering) ) {
//            if( undefinedp(buffering[buf]) ) continue;
//            if( !mapp(buffering[buf]) ) continue;

            tmp = "";
            cnt++;
            sk = uncolor( to_chinese(buf) );

            if ( cnt == 1 ) tmp += "│";
            tmp += sprintf("%-19s", sk + "("+ buffering[buf] + ")");
            tmp = replace_string(tmp, sk, to_chinese(buf) );
            if ( cnt%4 == 0 ) {
                cnt = 0;
                tmp += "\n";
            }
            msg += tmp;
        }
        if ( cnt != 0 ) msg += "\n";
        msg += "○──────────────────────────────────────○\n";
    }

    return msg;
}

int main(object me, string arg)
{
    object ob,weapon,horse;
    mapping my;
    string line, skill_type, model,*apply_id;
    int str1,con1,dex1,int1,bio1,bar1,wit1,sou1,tec1;

    
    seteuid(getuid(me));

    if (!arg) ob = me;
    else
    {
        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("你要察看誰的狀態﹖\n");
        if (!wizardp(me))
        {
            if (ob->query("creater")!=me)
                return notify_fail("只有巫師能察看別人的狀態。\n");
        }
    }
    /*--------------------------------------------------------------------------*/
    my = ob->query_entire_dbase();  //做資料轉換.
    line = "";
    //CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60)
    str1= ob->query_str();
    con1= ob->query_con();
    dex1= ob->query_dex();
    int1= ob->query_int();
    bio1= ob->query_bio();
    bar1= ob->query_bar();
    sou1= ob->query_sou();
    wit1= ob->query_wit();
    tec1= ob->query_tec();
    /*-------------------------------------------------------------*/
    if ( objectp(weapon = ob->query_temp("weapon")) )
        skill_type = weapon->query("skill_type");
    else skill_type = "unarmed";

    model=
        "╭──────────────────────────────────────○\n"
        "│  %12s  " HIW " %-52s"NOR"\n"
        "╰──────────────────────────────────────┤\n"
        "╭─────╮  等級 "HIY"%3d "NOR"級   年齡 "HIM"%2d "NOR"歲   種族 "HIG"%-6s"NOR"  性別 "HIC"%-2s"NOR"\n"
        "│"HIW"夢幻七域"NOR"  ├────────────────────────────────○\n"
        "├─────╯          生物(BIO)：%s%2d"NOR"(%2d)   生命(HP)：%s%6d"NOR" / %-6d         │\n"
        "│力量(STR)：%s%3d"NOR"(%3d)   獸性(BAR)：%s%2d"NOR"(%2d)   魔法(MP)：%s%6d"NOR" / %-6d         │\n"
        "│體質(CON)：%s%3d"NOR"(%3d)   魔法(WIT)：%s%2d"NOR"(%2d)   內勁(AP)：%s%6d"NOR" / %-6d         │\n"
        "│智慧(INT)：%s%3d"NOR"(%3d)   心靈(SOU)：%s%2d"NOR"(%2d)   擊殺玩家： %-10d             │\n"
        "│敏捷(DEX)：%s%3d"NOR"(%3d)   科技(TEC)：%s%2d"NOR"(%2d)   擊殺生物： %-10d             │\n"
        "○──────────────────────────────────────○\n"
        "│攻 擊 力： %-5d      攻擊技巧： %-5d    經 驗 值： %-14d         │\n"
        "│暴 擊 率： %-3d%%       閃躲技巧： %-5d    聲    望： %-14d         │\n"
        "│暴擊傷害： %-3d%%       物理防禦： %-5d    戰鬥藝術： %-14d         │\n"
        "│暴擊抵抗： %-3d%%       魔法防禦： %-5d    個性態度： %14s"NOR"         │\n"
        "○──────────────────────────────────────○\n"
        + "│" + getWarScoreBar( ob->query("war_score") ) + NOR"│\n"
        +"○──────────────────────────────────────○\n";


    line += sprintf(model,
                    RANK_D->query_rank(ob), sizeof(apply_id=ob->query_temp("apply/id"))? ob->short()+"  『 " +apply_id[sizeof(apply_id)-1]+" 』" : ob->short(),
                    ob->query("level"),ob->query("age"),to_chinese(ob->query("race")),ob->query("gender"),
                    attribute_color(bio1,my["Merits"]["bio"]),bio1,my["Merits"]["bio"],
                    status_color(my["hp"], my["max_hp"]), my["hp"], my["max_hp"],
                    attribute_color(str1,my["str"]),str1,my["str"], //參考 /feature/attribute.c
                    attribute_color(bar1,my["Merits"]["bar"]),bar1,my["Merits"]["bar"],
                    status_color(my["mp"],my["max_mp"]),my["mp"],my["max_mp"],
                    attribute_color(con1,my["con"]),con1,my["con"],
                    attribute_color(wit1,my["Merits"]["wit"]),wit1,my["Merits"]["wit"],
                    status_color(my["ap"],my["max_ap"]),my["ap"],my["max_ap"],

                    attribute_color(int1,my["int"]),int1,my["int"],
                    attribute_color(sou1,my["Merits"]["sou"]),sou1,my["Merits"]["sou"],
                    my["PKS"],

                    attribute_color(dex1,my["dex"]),dex1,my["dex"],
                    attribute_color(tec1,my["Merits"]["tec"]),tec1,my["Merits"]["tec"],
                    my["PKS"]+my["MKS"],

                    ob->query_damage(),
                    COMBAT_D->basic_attack_factor(ob),
                    my["exp"],

                    ob->query_hit(),
                    COMBAT_D->basic_dodge_factor(ob),
                    my["popularity"],
                        
                                        ob->query_hitpower(),
                    ob->query_armor(),
                    my["war_art"],

                                        ob->query_hit_against(),
                    ob->query_shield(),
                    attitude_report(ob->query("evil")),

                    ob->query("war_score")*100.0/10000.0
                   );

// add by -Acme-
    line += getConditionBuffer(ob);

    if (mapp(my=ob->query("wound")))
    {
        apply_id=keys(my);
        for (str1=0;str1<sizeof(apply_id);str1++)
        {
            if (ob->query("wound/"+apply_id[str1])>0)
                line += sprintf(HIW"  "+to_chinese(apply_id[str1])+"受傷程度:%s%3d%%\n"NOR,status_color(100-ob->query("wound/"+apply_id[str1]),100),ob->query("wound/"+apply_id[str1]));
        }
    }

//if(str1=ob->query_temp("conditions/poison")) line += sprintf(HIR+"體內毒素含量: %d%%\n"+NOR,str1);

    if (horse=ob->query_temp("ride"))
        line += sprintf("\n  你正坐在%s上。\n"NOR,horse->name());
    line +="\n";

    write(line);
    return 1;

}
string attitude_report(int evil_value)
{
    string outcome;
    outcome = "";
    if (!evil_value) evil_value = 0;
    if ( evil_value > 800 ) outcome += HIR "如同惡魔般邪惡";
    else if ( evil_value >= 600 ) outcome += HIM"極度凶殘      ";
    else if ( evil_value >= 400 ) outcome += HIM"十分邪惡      ";
    else if ( evil_value >= 200 ) outcome += HIY"非常頑劣      ";
    else if ( evil_value >= 50 ) outcome += HIY"有點惡劣      ";
    else if ( evil_value >= -50 ) outcome += "安分守己      ";
    else if ( evil_value >= -200 ) outcome += HIG"略為善良      ";
    else if ( evil_value >= -400 ) outcome += HIG"相當善良      ";
    else if ( evil_value >= -600 ) outcome += HIW"樂善好施      ";
    else if ( evil_value >= -800 ) outcome += HIW"俠義心腸      ";
    else outcome += HIC "有如天使般神聖";

    outcome += NOR;
    return outcome;
}
string attribute_color(int current, int value)
{
    if ( current > value ) return HIW;
    if ( current == value ) return NOR;
    if ( current < value ) return HBK;
}
string status_color(int current, int max)
{
    int percent;

    if ( max ) percent = current * 100 / max;
    else percent = 100;
    if ( percent > 100 ) return HIC;
    if ( percent >= 80 ) return HIG;
    if ( percent >= 60 ) return HIY;
    if ( percent >= 30 ) return HIM;
    return HIR;

}

int help(object me)
{
    write(@HELP
指令格式 : sccore (可縮寫為 sc)
           sc 自己的招喚生物
           sc <對象名稱>                   (巫師專用)

           這個指令可以顯示你(妳)或指定對象(含怪物)的基本資料。

           see also : hp, help setup
HELP
);
    return 1;
}


