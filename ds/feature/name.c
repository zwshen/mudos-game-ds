// name.c
// #pragma save_binary
#include <ansi.h>
#include <dbase.h>
#include <weapon.h>

nosave string *my_id;

void set_name(string name, string *id)
{
        set("name", name);
        set("id", id[0]);
        my_id = id;
}

int id(string str)
{
        string *applied_id;

        //if( this_player() && !this_player()->visible(this_object()) ) return 0;

        if( this_object()->is_character() && pointerp(applied_id = query_temp("apply/id")) 
        &&      sizeof(applied_id) ) 
                if( member_array(str, applied_id)!=-1 )
                        return 1;
                else
                        return 0;
                        
        // If apply/id exists, this object is "pretending" something, don't
        // recognize original id to prevent breaking the pretending with "id"
        // command.

        if( pointerp(my_id) && member_array(str, my_id)!=-1 )
                return 1;
        else
                return 0;
}

string *parse_command_id_list()
{
        string *applied_id;

        if( pointerp(applied_id = query_temp("apply/id")) 
        &&      sizeof(applied_id) )
                return applied_id;
        else
                return my_id;
}

varargs string name(int raw)
{
        string str, *mask;
        
        if( !raw && sizeof(mask = query_temp("apply/name")) )
                return mask[sizeof(mask)-1];
        else
        {  
                if(query_temp("invis") && !raw)
                {
                        if(this_object()->is_character()) return "某人";
                        else return "某物";
                }
                
                if(stringp(str = query("name"))) return str;
                
                return file_name(this_object());
        }
}

varargs string name_id(int raw)
{
        string str,*mask,*applied_id;
        if(raw)
        {
                str=query("name") + "(" + capitalize(query("id")) + ")";
        }
        else
        {
                if( query_temp("invis") || query_temp("hide") ) return "某人(Somebody)";
                if( sizeof( mask = query_temp("apply/short")) ) str = (string)mask[sizeof(mask)-1];
                        else str=query("name");
                if( sizeof( applied_id = query_temp("apply/id")) ) str +="("+capitalize((string)applied_id[sizeof(applied_id)-1])+")";
                        else str+="(" + capitalize(query("id")) + ")";
        }
        return str;
}

varargs string short(int raw)
{
          string title, nick, str, *mask;

        if(raw)
        {
                if( !stringp(str = query("short")) )
                        str = name(raw) + "(" + capitalize(query("id")) + ")";
        }
        else
        {
                if(sizeof(mask = query_temp("apply/short")) )
                        str = (string)mask[sizeof(mask)-1];
                else {
                        if(sizeof(mask = query_temp("apply/name")) )
                                str = (string)mask[sizeof(mask)-1];
                        else str = query("name");
                        if(sizeof(mask = query_temp("apply/id")) )
                                str += "("+capitalize((string)mask[sizeof(mask)-1])+")";
                        else str += "("+capitalize(query("id"))+")";
                        
                        if( stringp(nick = query("nickname")) )
                                str = sprintf("「%s」%s", nick, str);

                        if( stringp(title = query("title")) )
                                str = sprintf("%s%s%s", title,(nick?"":" "), str);
                }
/*
                if( !this_object()->is_character() || this_object()->is_corpse() )
                {
                        if(desc=this_object()->query("status_desc")) str+=" "+desc;//顯示目前狀態或兇手
                }
*/
        }
        
/*      if( !raw )
        {
                if(query_temp("sleeping")) str +="正在這裡睡覺";
                else if(query_temp("float")) str +="漂浮在空中";
                else if(query_temp("fly")) str +="在空中飛著";
                else if(query("fly")) str +="在空中飛來飛去";
                else if(objectp(ride_ob=query_temp("ride"))) //自訂騎乘顯示
                {
                        if(ride_type=ride_ob->query("ride_type")) str +=ride_type;
                        else str +="正騎在"+ride_ob->name()+"上";
                } else if(living(this_object()))
                        {
                                if(query("race")=="beast") str +="";
                                else if(query("race")=="beast") str+="正站在這裡";
                                else str+="在這裡";
                        }
                
                if(userp(this_object()))
                {
                        if( query_temp("netdead") ) str += HIG " <斷線中>" NOR;
                        if( in_input(this_object()) ) str += HIC " <輸入模式>" NOR;
                        if( in_edit(this_object()) ) str += HIY " <編輯檔案>" NOR;
                        if( interactive(this_object())
                        && query_idle( this_object() ) > 120 )
                          str += HIM " <發呆 " + (query_idle(this_object())/60) " + "分鐘" NOR;
                }
                
                if( !living(this_object()) ) str += HIR + query("disable_type") + NOR;
                
                if(desc=this_object()->query("status_desc")) str+=" "+desc;//顯示目前狀態或兇手
        }
*/
        return str;
}

varargs string long(int raw)
{
        string str, extra, *mask;
        
        if( !raw && sizeof(mask = query_temp("apply/long")) )
                str = mask[sizeof(mask)-1];
        else if( !stringp(str = query("long")) )
                str = short(raw) + "。\n";

        if( stringp(extra = this_object()->extra_long()) )
                str += extra;

        return str;
}

varargs string item_describe(int only_name)
{
        string type,armor,race_armor_type,skill_type;
        int flag;
          object owner;
        if(query("equipped"))
        {
                if( (owner = environment())->is_character() )
                {
                        // Find owner's Race
                        switch(owner->query("race"))
                        {
                case "人類" :
                case "human" : 
                case "妖魔" :
                case "evil" : 
                case "仙派" :
                case "celestial" : 
                case "獸人" :
                case "ogre" : 
                case "虎人" :
                case "tiger" : 
                                        race_armor_type="armor_type";
                                                break;
                                case "野獸" :
                                case "beast" :
                                                race_armor_type="beast_armor_type";
                                                break;
                                case "異型" :
                                case "zerg" :
                                                race_armor_type="zerg_armor_type";
                                                break;
                                case "神族" :
                                case "protoss":
                                                race_armor_type="protoss_armor_type";
                                                break;
                                default :
                                                race_armor_type="armor_type";
                        }
                } else race_armor_type = "armor_type";
        
                if(skill_type=query("skill_type"))
                {
                 if(skill_type=="parasite") type="生化融合";
                 else
                 {
                        flag=query("flag");
                        if( flag & TWO_HANDED ) type="雙手使用";
                        else type="單手使用";
                 }
                } 
                else if(armor=query(race_armor_type))
                {
                 switch(armor)
                 {
                  case "head": type="頭上戴著";
                                 break;
                  case "neck": type="脖子掛著";
                                 break;
                  case "cloth": type="身上穿著";
                                 break;
                  case "armor": type="身上覆著";
                                 break;
                  case "surcoat": type="肩上披著";
                                 break;
                  case "waist": type="腰上綁著";
                                 break;
                  case "wrists": type="手腕纏著";
                                 break;
                  case "shield": type="一手裝著";
                                 break;
                  case "finger":
                  case "ring": type="手指戴著";
                                 break;
                  case "hands": type="手掌套著";
                                 break;
                  case "boots": type="腳上穿著";
                                 break;
                  case "legging": type="腿上穿著";
                                 break;
                  case "mask": type="臉上戴著";
                                 break;
                  case "pants": type="下身穿著";
                                 break;
                  case "ankle": type="足踝綁著";
                                 break;
                  default: type="身上戴著";
                 }
                }
                else type="正裝備著";
        }
        else return sprintf("%s", short() );
        if(!only_name)
                return sprintf("%s%s",
                        short(),
                        HIG+" ("+type+") "NOR,
                        );
        else 
                return sprintf("%s%s",
                        HIC+"  ["+type+"]  "+NOR,
                        short()
                        );
}


