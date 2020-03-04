/* щ布絚 write by whatup 2003/06/26 */
//rewrite by promise@DS
#include <ansi.h>

inherit F_SAVE;
inherit ITEM;

private void enter_vote(string arg,int num,int);
string query_short();
int open_vote(string);
void create()
{
        set_name(HIC"⒈⒉⒁⑨材щ布诀竟"NOR,({ "vote machine","vote","machine"}));
        set("no_get",1);
        set("no_sac",1);
        set("value",10000000000);
        
        restore();
        set("short",(:query_short:));
}
void init()
{
        if(wiz_level(this_player())>0 )
        {
                add_action("add_vote","add_vote");
                add_action("reset_vote","reset_vote");  
                add_action("open_vote","open_vote");
        }

        if(query("mode")==2 ) return ;
        if(query("vote_data/stop_time") && query("vote_data/stop_time")<time())
        {
                open_vote("");
                return ;
        }
        add_action("vote","vote");
}
int save()
{
        if(!clonep()) ::save();
}
string query_save_file()
{
        return DATA_DIR"votebox";
}
int reset_vote()
{
        delete("vote_data");
        delete("vote_user");
        delete("vote");
        delete("mode");
        write("竚ЧΘ\n");
        save();
        return 1;
}
// 穝糤穝щ布
int add_vote(string arg)
{
        object me=this_player();
        int num,i,day;
        string long;
        if(wiz_level(me)<6 )
                return 0;
        if(query("vote_data")) 
                return notify_fail("瞷щ布タ秈︽い\n");
        if(!arg || sscanf(arg,"%d %d %s",num,day,long)!=3)
                return notify_fail("add_vote <匡布计> <ぱ计> <弧>\n");
        if(num < 1 )
                return notify_fail("匡布计程ぶ璶Τ\n");
        if(day > 7 || day < 1)
            return notify_fail("ぱ计 1 - 7ぱ\n");
        set("vote_data/long",long);
        set("vote_data/start_time",time());
        // 箇砞ぱ碞秨布
        set("vote_data/stop_time",time() + day * 86400);
        set("mode",1);
        i=0;
        write("叫块材 "+(i+1)+" 眎匡布弧");
        input_to((:enter_vote:),1,num,i);
        return 1;
        
}
void enter_vote(string arg,int num,int i)
{
        if(!arg) {
                write("﹚璶块狥﹁叫ㄓΩ");
                input_to((:enter_vote:),1,num);
                return ;
        }
        set("vote/"+i,arg);
        if(num==1) 
        {
                write("ЧΘ\n");
                save();
                return ;
        }
        
        i++;
        num--;
        write("叫块材 "+(i+1)+" 眎匡布弧");
        input_to((:enter_vote:),1,num,i);
        
}
string extra_long()
{
        string str;

        if(!query("vote")) return "瞷⊿Τヴщ布";
        if(query("mode") == 2)
        {
                return "щ布挡狦:\n"+query("vote_data/final");;
        }
         str= sprintf("щ布弧
        %s
",query("vote_data/long") );
        foreach( string num in sort_array(keys(query("vote")),1))
        {
                if(num == query("vote_user/"+getuid(this_player()))) str += HIW"》"NOR;
                else str += "  ";
                str += sprintf("  [%s] %s\n",num,query("vote/"+num));
        }
        str += "\n\t临Τ "+ FINGER_D->age_string(query("vote_data/stop_time")-time())+ " 碞秨布穛叫戳\n";
        return str;
}
string query_short()
{
        object me=this_player();
        if(query("mode")==2)
        {
                return name()+ "(" + capitalize(query("id")) + ")〓 щ布挡 "+sizeof(query("vote_user"))+" щ布";
        }
        if(query("mode")==1)
        {
                string str;
                str = (query("vote_user/"+me->query("id")))?"竒щ布":HIR"﹟ソщ布"NOR;
                return name()+ "(" + capitalize(query("id")) + ")〓 "+sizeof(query("vote_user"))+" щ布 - "+str;
        }
        if(query("mode")==0)
        {
                return name()+ "(" + capitalize(query("id")) + ")〓ヘ玡⊿Τヴщ布";
        }
}
int vote(string arg)
{
        
        if(query("mode")!=1) return 1;
        if(query("vote_user/"+getuid(this_player()))) return notify_fail("竒щ筁瓳\n");
        if(!arg) return notify_fail("璶щê\n");
        if(!query("vote/"+arg)) return notify_fail("⊿Τ硂匡兜瓳\n");
        set("vote_user/"+getuid(this_player()),arg);
        save();
        message_vision("$Nщ竧布\n",this_player());
        return 1;
}
int open_vote(string arg)
{
        mapping fin;
        string *votes;
        string str;
        
        if(wiz_level(this_player())<6 )
                return 0;       
                
        fin = allocate_mapping(sizeof(query("vote")));
        votes = values(query("vote_user"));
        str = query("vote_data/long")+"\n挡狦 \n";
        
        foreach(arg in keys(query("vote")))
        {
                fin[arg] = sizeof(filter_array(votes,(: $1 == $2:),arg));
        }
        votes = sort_array(keys(fin),1);
        foreach(arg in votes)
        {
                str += sprintf("[%s] %-30s Τ %-3d 眎布\n",arg,query("vote/"+arg),fin[votes[to_int(arg)]]);
        }
        set("mode",2);
        set("vote_data/final",str);
        write("秨布Θ\n");          
        write("程挡狦\n"+str);
        save();
        return 1;
}

