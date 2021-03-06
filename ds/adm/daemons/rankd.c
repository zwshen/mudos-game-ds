// rankd.c
// 更新日期: 1999.10.23
// 更新者: Shengsan

#include <ansi.h>

string query_rank(object ob)
{
          string eff_class, id;
        if( ob->query("class2") ) eff_class=ob->query("class2");
        else if( ob->query("class1") ) eff_class=ob->query("class1");
        else if( ob->query("class") ) eff_class=ob->query("class");
        else eff_class="none";

        if( ob->is_ghost() ) return HIB "【 鬼  魂 】" NOR;
        id=ob->query("id");
        if(wizardp(ob))
        {
                 switch(wizhood(ob))
                  {
                        case "(admin)":                 return HIW "【 大  神 】" NOR;
                        case "(arch)":                  return HIY "【 大巫師 】" NOR;
                        case "(wizard)":                return HIG "【 巫  師 】" NOR;
                        case "(apprentice)":    return HIM "【 見習生 】" NOR;
                        default:                                return HIM "【 座  客 】" NOR;
                  }
        }        
        
        switch(ob->query("gender"))
        {
                case "女性":
                        if( ((int)ob->query("PKS") > 4999) ) return HIM"【 修  羅 】"NOR;
                        if( ((int)ob->query("PKS") > 999) ) return HIM"【 千人斬 】"NOR;
                        if( ((int)ob->query("PKS") > 99) ) return HIR"【 百人斬 】"NOR;
                        if( ((int)ob->query("PKS") > 30) ) return RED"【 殺人魔 】"NOR;
                        switch(eff_class)
                        {
                            case "八極門":        return "【 女武者 】";
                            case "疾風門":        return "【 女劍客 】";
                            case "神武教":                return "【 女道士 】";
                            case "thief":                return "【 女  盜 】";
                            case "凌雲寺":                return "【 尼  姑 】";
                            case "adventurer":        return "【 女勇者 】";
                            case "情城池":                return "【 女鞭手 】";
                            case "寒澈派":        return "【 女道姑 】";
                            case "少帥軍":        return "【 軍  人 】";
                            case "邪極宗":        return "【 魔  門 】";
                            case "天梟派":        return "【 女針師 】";
                            default:                return "【 小女孩 】";
                        }         
        
                default:
                        if( ((int)ob->query("PKS") > 4999) ) return HIM"【 死  神 】"NOR;
                        if( ((int)ob->query("PKS") > 999) ) return HIM"【 千人斬 】"NOR;
                        if( ((int)ob->query("PKS") > 99) ) return HIR"【 百人斬 】"NOR;
                        if( ((int)ob->query("PKS") > 30) ) return RED"【 殺人魔 】"NOR;
                        switch(eff_class)
                        {
                            case "八極門":        return "【 武  者 】";
                            case "疾風門":        return "【 劍  客 】";
                            case "神武教":        return "【 道  士 】";
                            case "thief":         return "【 小  偷 】";
                            case "adventurer":    return "【 冒險者 】";
                            case "凌雲寺":        return "【 僧  侶 】";
                            case "寒澈派":        return "【 道  士 】";
                            case "少帥軍":        return "【 軍  人 】";
                            case "邪極宗":        return "【 魔  門 】";
                            case "天梟派":        return "【 針  師 】";
                            default:              return "【 新  手 】";
                        }
        }
}

string query_level(object ob)
{
          string rank;
        rank = ob->query("guild_rank");
        if(!rank) {
                if( ob->query("gender") == "女性" )
                        rank = "初染風塵的小美女";
                else
                        rank = "四處為家的流浪漢";        
        }
        
        return rank;
}


string query_respect(object ob)
{
        int age;
        string str,eff_class;
        if(!ob) return "朋友";
        if( stringp(str = ob->query("rank_info/respect")) )
                return str;
        if(ob->query("race")=="beast") return "靈獸";
        if(ob->query("race")=="monster") return "靈獸";
        if(ob->query("race")=="protoss")
                return "神族朋友";
        if(ob->query("race")=="zerg")
                return "異型朋友";

        if( ob->query("class2") ) eff_class=ob->query("class2");
        else if( ob->query("class1") ) eff_class=ob->query("class1");
        else if( ob->query("class") ) eff_class=ob->query("class");
        else eff_class="none";
        
        age = ob->query("age");
        switch(ob->query("gender"))
        {
                case "女性":
                        switch(eff_class)
                        {
                                case "none":
                                default:
                                                if( age < 18 ) return "小妹妹";
                                                else if( age < 30 ) return "姑娘";
                                                else if( age < 50 ) return "小姐";
                                                else if( age < 70 ) return "太太";
                                                else if( age < 100 ) return "婆婆";
                                                else return "老前輩";
                                                break;
                        }

                default:
                        switch(eff_class)
                        {
                                case "none":
                                default:
                                                if( age < 20 ) return "小弟弟";
                                                else if( age < 30 ) return "兄台";
                                                else if( age < 60 ) return "叔叔";
                                                else if( age < 80 ) return "阿公";
                                                else if( age < 100 ) return "老公公";
                                                else return "老前輩";
                                                break;
                        }
        }
}

string query_rude(object ob)
{
        int age;
        string str,eff_class;
        if(!ob) return "混蛋";
        if( stringp(str = ob->query("rank_info/rude")) )
                return str;
        if(ob->query("race")=="野獸") return "畜生";
        if(ob->query("race")=="monster") return "妖怪";
        if(ob->query("race")=="protoss")
                return "醜八怪";
        if(ob->query("race")=="zerg")
                return "大臭蟲";

        if( ob->query("class2") ) eff_class=ob->query("class2");
        else if( ob->query("class1") ) eff_class=ob->query("class1");
        else if( ob->query("class") ) eff_class=ob->query("class");
        else eff_class="none";

        age = ob->query("age");
        switch(ob->query("gender"))
        {
                case "女性":
                        switch(eff_class)
                        {
                                case "none":
                                default:
                                        if( age < 20 ) return "雜種";
                                        if( age < 40 ) return "賤人";
                                        if( age < 60 ) return "妖女";
                                        if( age < 100 ) return "老妖女";
                                        return "妖婦";
                                        break;
                        }
                        
                default:
                        switch(eff_class)
                        {
                                case "none":
                                default:
                                                if( age < 20 ) return "混球";
                                                if( age < 50 ) return "臭賊";
                                                if( age < 80 ) return "老不死";
                                                return "老怪物";
                                                break;
                        }
        }
}

string query_self(object ob)
{
        int age;
        string str,eff_class;

        if( stringp(str = ob->query("rank_info/self")) )
                return str;
        if(ob->query("race")=="野獸") return "我";
        if( ob->query("class2") ) eff_class=ob->query("class2");
        else if( ob->query("class1") ) eff_class=ob->query("class1");
        else if( ob->query("class") ) eff_class=ob->query("class");
        else eff_class="none";
        
        age = ob->query("age");
        switch(ob->query("gender"))
        {
                case "女性":
                        switch(eff_class)
                        {
                                case "none":
                                default:
                                                if( age < 30 ) return "小妹";
                                                else return "在下";
                                                break;
                        }
        
                default:
                        switch(eff_class)
                        {
                                case "none":
                                default:
                                                if( age < 50 ) return "在下";
                                                else return "老頭子";
                                                break;
                        }
        }
}

string query_self_rude(object ob)
{
        int age;
        string str,eff_class;

        if( stringp(str = ob->query("rank_info/self_rude")) )
                return str;
        if(ob->query("race")=="野獸") return "我";
        if( ob->query("class2") ) eff_class=ob->query("class2");
        else if( ob->query("class1") ) eff_class=ob->query("class1");
        else if( ob->query("class") ) eff_class=ob->query("class");
        else eff_class="none";

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "女性":
                        switch(eff_class)
                        {
                                case "none":
                                default:
                                                if( age < 40 ) return "本姑娘";
                                                else return "老娘";
                                                break;
                        }
                        
                default:
                        switch(eff_class)
                        {
                                case "none":
                                default:
                                                if( age < 50 ) return "本大爺";
                                                else return "老夫";
                                                break;
                        }
        }
}

