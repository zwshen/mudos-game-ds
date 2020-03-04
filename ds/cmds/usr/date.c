
inherit F_CLEAN_UP;
#include <localtime.h>
#include <ansi.h>
int main(object me,string arg)
{
	mixed *local;
	string week;
//        write(sprintf("²{¦b®É¨è¬O¡R¡i%s¡j¡C\n",ctime(time()) ) );
        local = localtime(time());
        switch(local[LT_WDAY])
        {	
        	case 0: week=HIR+"¤é"; break;
        	case 1: week="¤@"; break;
        	case 2: week="¤G"; break;
        	case 3: week="¤T"; break;
        	case 4: week="¥|"; break;
        	case 5: week="¤­"; break;
        	case 6: week=HIR+"¤»"; break;
        	default: week="??"; break;
        }
	write(sprintf(HIC"²{¦b®É¨è¬O¡R"HIM"¡i"HIG"¦è¤¸%d¦~%d¤ë%d¤é "HIY"¬P´Á%s"HIW" %d[1;5m:[0m"HIW"%2d"HIM"¡j"NOR"\n",
		local[LT_YEAR],local[LT_MON]+1,local[LT_MDAY],week,
		local[LT_HOUR],local[LT_MIN] ) );
        return 1;
}

int help(object me)
{
     write(@HELP
«ü¥O®æ¦¡: date

³o­Ó«ü¥OÅý§A(©p)ª¾¹D²{¦bªº¨t²Î®É¶¡

HELP
    );
    return 1;
}
