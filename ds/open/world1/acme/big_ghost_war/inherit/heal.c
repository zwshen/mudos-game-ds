/* include 檔 write by -Acme-
*/

#include <ansi.h>

void do_heal(object who, string type);

void do_heal(object who, string type)
{
    if( !objectp(who) || who->is_busy() ) return;
    switch( type ) {
        case "hp":
            if( who->query("hp") > who->query("max_hp")*2/3 
             || who->query("ap") < who->query("max_ap")/2 ) return;
            message_vision(CYN"$N臉色一沉，一股綠氣罩住全身，氣色似乎好了許\多。\n"NOR, who);
            who->receive_heal("hp", who->query("level")+(random(who->query("level"))+1)*3);
            who->receive_damage("ap", 30);
            break;
        case "ap":
            if( who->query("ap") > who->query("max_ap")*2/3 
             || who->query("mp") < who->query("max_mp")/2 ) return;
            message_vision(CYN"$N臉色一沉，一股黑氣罩住全身，勁力似乎加強了不少。\n"NOR, who);
            who->receive_heal("ap", who->query("level")+(random(who->query("level"))+1)*3);
            who->receive_damage("mp", 30);
            break;
        case "mp":
            if( who->query("mp") > who->query("max_mp")*2/3 
             || who->query("ap") < who->query("max_ap")/2 ) return;
            message_vision(CYN"$N臉色一沉，一股紅氣罩住全身，精神似乎好了許\多。\n"NOR, who);
            who->receive_heal("mp", who->query("level")+(random(who->query("level"))+1)*3);
            who->receive_damage("ap", 30);
            break;
    }
    return;
}
