// emoted.c
// #pragma save_binary
#include <net/dns.h>
#include <net/emote.h>
#include <ansi.h>
#include <mudlib.h>
//#include <net/i3.h>
inherit F_SAVE;
mapping emote;

string net_emote(object me,string verb,string rest);

//        The emote mapping contains the data base of emote definitions. Each emote
//        is defined in a sub-mapping with the following structure:
//
//        myself        - the message emoter will see
//        target        - the message the target will see when targeted
//        others        - the message others will see when no argument.
//
//        The emote mapping is indexed with the emote 'pattern' instead of emote
//        verb. For example, typing "smile" without argument will cause the daemon
//        search the emote mapping with "smile" as key, and typing "smile someone"
//        will cause the daemon search the emote mapping with "smile $" pattern as
//        the key, while $ means one argument.
//
//        In the message string, the following substitutions will be applied before
//        sending the messages:
//
//        $N                - name of emoter
//        $n                - name of target
//        $P                - pronoun of emoter
//        $p                - pronoun of target
//        $T                - second argument of emote
//
//        Original by Annihilator@ESII (11/09/94)
//	  Modified by Kenny@Broken.History (09/22/1996)
//	  Add intermud support stuff - Luky@DS (09/25/2000)
void create()
{
        seteuid(getuid());
        if( !restore() && !mapp(emote) )
                emote = ([]);
}
int remove()
{
        save();
        return 1;
}
string query_save_file() { return DATA_DIR + "emoted"; }
// command_hook() of F_COMMAND call this as an alternate command processor.
// CHANNEL_D also calls this to get emote message.
varargs mixed do_emote(object me, string verb, string arg, int channel_emote, string anonymous)
{
        string str, my_gender, target_gender, msg_postfix, rest="",tar, call_me,call_target;
        object target,owner;

	if( !environment(me) ) return 0;

	if ( !mapp(emote) || undefinedp(emote[verb]) ) return 0;
	
	if(!userp(me))
	{
		if( owner=me->query("creater") )
		{
			if(owner->query("talk_point")<1) return 0;
			owner->add("talk_point",-1);
		}
	}
	else if( !wizardp(me) && me->query("talk_point")< 1 ) return notify_fail("�A�{�b�f������, �n���@�U�~���O�𻡸ܳ�!\n");
	if( me->query("putjail_position") ) return notify_fail("�A�{�b�S�����ܪ��v�Q!\n"); //���_�Ӫ��H
        // Determine the pattern to be searched and the target.
        if(stringp(arg) && arg != "" )
        {
/*
		//intermud check
		if( previous_object() && base_name(previous_object()) != CHANNEL_D)
		{
			if(sscanf(arg,"%s@%s",iwho,imud)==2)
			{
				if(sscanf(imud,"%s %s",imud,irest)!=2) irest="";
				if(str = net_emote(me,verb,irest))
				{
					imud = replace_string(imud,"."," ");
					I3_EMOTETO->send_emoteto(geteuid(me),me->name(1),imud,iwho,str);
					str = emote[verb]["myself_target"];
					str = replace_string(str, "$N", me->name());
                			str = replace_string(str, "$P", "�A");
                			str = replace_string(str, "$n", iwho+"@"+imud);
                			str = replace_string(str, "$p", "�L");
                			str = replace_string(str, "$T", irest);
					write(HIG + str + "\n"+NOR);
					write("I3�����T���w�e�X�M�i��n�y�Ԥ~��o��^���C\n");
					return 1;
				}			
			}
		}
*/
		if(sscanf(arg, "%s %s", tar, rest)!=2)
		{
			target=present(arg,environment(me));
			if(!target && (!userp(me) || wizardp(me) || channel_emote>1)) target=find_living(arg);
			if(target) if(!me->visible(target)) target=0;
			if(!target ) rest=arg;
		}
		 else
		{
			target=present(tar,environment(me));
			if(!target && (!userp(me) || wizardp(me) || channel_emote>1)) target=find_living(tar);
			if(target) if(!me->visible(target)) target=0;
			if(!target) rest=arg;
        	}
 
		if(!objectp(target)) //�ۤv
		{
                        // If not channel emote, only search target in our environment.
                        if(channel_emote==LOCAL_EMOTE || channel_emote==ANONYMOUS_LOCAL_EMOTE)
                        {
				if(stringp(str=emote[verb]["others"]))
                                {
					if(strsrch(str,"$T")==-1)
					{
						me->add_temp(EMOTE_ERROR,1);
						return notify_fail("�A�����D�n��ְ��o�Ӱʧ@�C\n");
					}
                                       	if(rest) str = replace_string(str, "$T", rest);
                                        else str = replace_string(str, "$T", "...");
                                        message_vision(str, me);
         				if( !wizardp(me) && userp(me)) me->add("talk_point",-1);
                                        return 1;
                                }
                                return 0;
                        }
                        //�W�D�ʧ@
			if(stringp(str=emote[verb]["others"]))
                        {
                                        if(strlen(rest))
                                        {
                                        	str = replace_string(str, "$T", rest);
					}
                                        else str = replace_string(str, "$T", "...");

                            switch(channel_emote)
                            {
                             	case LOCAL_EMOTE:
                             		call_me=me->name_id();
                             		break;
                             	case ANONYMOUS_LOCAL_EMOTE:
                             		call_me="�Y�H";
                             		break;
                             	case LOCAL_CHANNEL_EMOTE:
                             		call_me=me->name_id(1);
                             		break;
                             	case ANONYMOUS_CHANNEL_EMOTE:
                             		call_me="�Y�H";
                             		break;
                             	case NET_CHANNEL_EMOTE:
                             	default:
                             		call_me=me->query("name")+"("+capitalize(me->query("id"))+"@"+INTERMUD_MUD_NAME+")";
                            }
                            str = replace_string(str, "$N", stringp(anonymous)? anonymous: call_me);
                            return str;
                        }
                        return "";
                }
                
                if (!(target_gender = target->query("gender")))
                        target_gender = "�D�ͪ�";           // �D�ͪ�
                if( target==me )
                {
                        msg_postfix = "_self";
                        target = 0;
                }
                else msg_postfix = "_target";
	} else msg_postfix = "";
        my_gender = me->query("gender");
        switch(channel_emote)
        {
               	case LOCAL_EMOTE:
	       		call_me=me->name_id();
	       		if(objectp(target)) call_target=target->name_id();
             		break;
             	case ANONYMOUS_LOCAL_EMOTE:
               		call_me="�Y�H";
               		if(objectp(target)) call_target=target->name_id();
              		break;
            	case LOCAL_CHANNEL_EMOTE:
              		call_me=me->name_id(1);
              		if(objectp(target)) call_target=target->name_id(1);
              		break;
              	case ANONYMOUS_CHANNEL_EMOTE:
               		call_me="�Y�H";
               		if(objectp(target)) call_target=target->query("name")+"("+capitalize(target->query("id"))+")";
          		break;
              	case NET_CHANNEL_EMOTE:
               	default:
              		call_me=me->query("name")+"("+capitalize(me->query("id"))+"@"+INTERMUD_MUD_NAME+")";
              		if(objectp(target)) call_target=target->query("name")+"("+capitalize(target->query("id"))+"@"+INTERMUD_MUD_NAME+")";
        }

        if( stringp(str = emote[verb]["myself" + msg_postfix]) )
        {
                str = replace_string(str, "$N", call_me);
                str = replace_string(str, "$P", gender_self(my_gender));
                if( objectp(target) )
                {
                        str = replace_string(str, "$n", call_target);
                        str = replace_string(str, "$p", gender_pronoun(target_gender));
                }
                str = replace_string(str, "$T", rest);
 		if( channel_emote<LOCAL_CHANNEL_EMOTE )
 		{
 			message("emote", YEL + str + NOR, me);
 			if( !wizardp(me)) me->add("talk_point",-1);
 			if(me->query_temp(EMOTE_ERROR)==MAX_ERROR_COUNT) me->add_temp(HALT_EMOTE,1);			
 		}
	}
	
        if( objectp(target) && stringp(str = emote[verb]["target"]) )
        {
                str = replace_string(str, "$N", call_me);
                str = replace_string(str, "$P", gender_pronoun(my_gender));
                str = replace_string(str, "$n", call_target);
                str = replace_string(str, "$p", gender_self(target_gender));
                str = replace_string(str, "$T", rest);
                if( channel_emote<LOCAL_CHANNEL_EMOTE  ) message("emote", GRN + str + NOR, target);
	}
	
        if( stringp(str = emote[verb]["others"+msg_postfix]) )
        {
                str = replace_string(str, "$N", call_me);
                str = replace_string(str, "$P", gender_pronoun(my_gender));
                if( objectp(target) )
                {
                        str = replace_string(str, "$n", call_target);
                        str = replace_string(str, "$p", gender_pronoun(target_gender));
                }
                str = replace_string(str, "$T", rest);

 		if( channel_emote<LOCAL_CHANNEL_EMOTE )
 		{
 			message("emote",YEL+ str + NOR,environment(me), ({me, target}));
 		}
	}
        
        if(channel_emote>=LOCAL_CHANNEL_EMOTE) return str;
        
        // Let NPC know we are doing emote on him.
        if( objectp(target) ) target->relay_emote(me, verb);
        return 1;
}
 
int set_emote(string pattern, mapping def)
{
        emote[pattern] = def;
        save();
        return 1;
}
int delete_emote(string pattern)
{
        map_delete(emote, pattern);
        save();
        return 1;
}
mapping query_emote(string pattern)
{
        if( !undefinedp(emote[pattern]) ) return emote[pattern];
        else return ([]);
}
string *query_all_emote()
{
        return keys(emote);
}

string net_emote(object me,string verb,string rest)
{
	string str;
	if(undefinedp(emote[verb]) || !(str = emote[verb]["target"]) ) return 0;

        str = replace_string(str, "$P", (me->query("gender")=="�k��")? "�p":"�A");
        str = replace_string(str, "$T", rest);
	return str;
}
