// alias.c

inherit F_CLEAN_UP;

string *banned_alias = ({
	"alias", "do", "drink", "kill", "look", "inventory", "balance",
	"cast", "exert", "go","ask","get","drop","give","east","west","up",
	"down","north","south","search","drink","eat","fight","say","chat","tchat",
	"shout","tell","reply","shoot","use","wear","wield","remove","unwield",
	"talk","surrender","ride","open","lock","sac","combine","follow","whisper",
	"suicide","team","party","put","close","emote","semote","relieve","finger",
	"followup","finger","read","help","hp","id","level","nick","passwd","quit",
	"recall","report","score","secure","search","skills","spells","to","tune",
	"unset","set","save","who","uptime","wimpy","describe","ex","c","m","map",
});

int main(object me, string arg)
{
	int i;
	mapping alias;
	string verb, replace, *vrbs;

	if( !arg ) {
		alias = me->query_all_alias();
		if( !sizeof(alias) ) {
			write("你目前並沒有設定任何 alias。\n");
			return 1;
		} else  {
			write("你目前設定的 alias 有﹕\n");
			vrbs = keys(alias);
			vrbs = sort_array(vrbs, "sort_verb", this_object());
			for(i=0; i<sizeof(vrbs); i++)
				printf("%-15s = %s\n", vrbs[i], alias[vrbs[i]]);
			return 1;
		}
	}

	if( sscanf(arg, "%s %s", verb, replace)!=2 )
		me->set_alias(arg, 0);
	else if( member_array(verb, banned_alias)!=-1 )
	        return notify_fail(" \""+verb+"\"為系統指令. 請使用其他名稱。\n");
	else if( verb=="alias" )
		return notify_fail("你不能將 \"alias\" 指令設定其他用途。\n");
	else if( verb=="" )
		return notify_fail("你要設什麼 alias﹖\n");
	else
		return me->set_alias(verb, replace);

	write("Ok.\n");
	return 1;
}

int sort_verb(string verb1, string verb2)
{
	return strcmp(verb1,verb2);
}


int help (object me)
{
	write(@HELP
指令格式 : alias <欲設定之指令> <系統提供之指令>
 
有時系統所提供之指令需要輸入很長的字串, 在使用時(尤其是經常用到的)
或許會感覺不方便, 此時你(妳)即可用此一指令設定並替代原有之指令。
 
範例:
	'alias sc score' 會以 sc 取代 score 指令。
	'alias' 後不加參數則列出你所有的替代指令。
	'alias sc' 會消除 sc 這個替代指令。 (如果你有設的話)
 
其中可以用 $1, $2, $3 .... 來取代第一、第二、第三個參數﹐或是 $* 取代
所有的參數﹐如﹕
	'alias pb put $1 in $2'

則每當你(妳)打﹕
	pb bandage bag

就會取代成﹕
	put bandage in bag
	
HELP
);
        return 1;
}
