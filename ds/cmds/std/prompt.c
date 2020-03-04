// 郎: /cmds/std/prompt.c
// : Shengsan@DS
// ら戳: 2000/05/17

#include <ansi.h>

inherit F_CLEAN_UP;

int provar(object me,string type);

int main(object me,string arg)
{

	
	if( strlen(arg) > 50 )
		return notify_fail("矗ボじび\n");

	if(!arg || arg=="all")
//		arg = "<ネ㏑%h 臸猭%m ず玪%a>";
		if (wiz_level(me)>1)
			arg = "%L> ";	// 畍箇砞
		else
			arg = "> ";	// 產箇砞

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	me->set("dssystem/prompt/form",arg);
	write("Ok...\n");
	return 1;
}

int help(object me)
{
     write(@HELP
Α: prompt 把计

把计:
	%%	陪ボ % 才腹
	%h 	ヘ玡ネ㏑翴计
	%H	程ネ㏑翴计
	%m	ヘ玡臸猭翴计
	%M	程臸猭翴计
	%a	ヘ玡ず玪翴计
	%A	程ず玪翴计
	%T	ヘ玡┮矪
	%c	ヘ玡驹矮竒喷
	%x	ヘ玡竒喷
	%l	ヘ玡皚犁
	%~	础传︽じ
	%L	ヘ玡ヘ魁(畍ㄏノ)

弧: 狦⊿Τヴ把计, 碞穦箇砞秈︽砞﹚. 箇砞 > 
      穎皌肅︹ㄓ暗恶︹, 叫 help nick

絛ㄒ: prompt <$HIR$ネ㏑$NOR$ %h>

HELP
    );
    return 1;
}

