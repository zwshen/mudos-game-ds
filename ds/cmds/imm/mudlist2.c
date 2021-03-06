// New mudlist command for I3 system
// Added some enhancements, Avatar of Eodon, 09/19/95
// Added some enhancements, Slc/Brainstorm May 96
// fixed some bug, Luky of ds.muds.net 7000 Sep 2K

#include <net/i3.h>

inherit F_CLEAN_UP;
 
#define        SYNTAX        "格式: mudlist [-a] [mudname]\n"
void create() { seteuid(getuid(this_object())); }

string *format_info(string name,mixed vls,string option)
{
  string flags="";
  mapping services=vls[11];
    
  flags += (services["tell"])  ? "* ":"  ";
  flags += (services["who"])  ? "* ":"  ";
  flags += (services["finger"]) ? "* ":"  ";
  flags += (services["locate"]) ? "* ":"  ";
  flags += (services["channel"]) ?  "* ":"  ";
  flags += (services["news"]) ? "* ":"  ";
  flags += (services["mail"]) ? "* ":"  ";

  return ((vls[0]==-1) || (option=="-a")) ?
    ({sprintf("%-15s%-17s%6d%c %-15s %s",
            name[0..14], (vls[0]!=-1) ? "(" + vls[1] : " " + vls[1] ,vls[2],
            (vls[0]!=-1) ? ')' : ' ',
            vls[5][0..14], flags)}):
    ({});
}
 
int main(object me,string args)
{
  string *mud,flags;
  mixed *vls;
  int i,j;
  mapping list,newlist;
  string option="";
  string *result=({}),*sorted=({}),output;

  list = I3_DAEMON->query_mudlist();
  if (!sizeof(list))
  { 
    message("error","No muds on I3 Network!\n", this_player() ); 
    return 1;
  }

  mud = keys(list);
  vls = values(list);
  
  result = ({"I3泥網目前共有 "+sizeof(mud)+" 個泥巴連線中. (使用Router:"+ROUTER_NAME+")\n",
             sprintf("%-15s %-17s %-5s %-15s %s","Name","IP","Port",
                     "MudLib","T W F L C N M L"),
             sprintf("%-15s %-17s %-5s %-15s %s","----","--","----",
                     "------","- - - - - - - -")});

  j = -1;

  if (args && args!="")
  {
    string name=args;

    if (sscanf(args,"%s %s",option,name)==2 && option!="-a")
    {
      write(SYNTAX);
      return 1;
    }
    else
      if (args=="-a")
      {
        option = "-a";
        name = "";
      } else
	option = "-a";  /* test by SLC */ 

    args = name;

/*    if (name!="" && (j=member_array(name,mud))==-1)
    {
      write("Sorry, the mud "+args+" is not in the list right now. Try again "+
            "later.\n");
      return 1;
    } */
 
  }
  else { args = "";  option = "-a"; }
  if (j != -1)
    sorted += format_info(mud[j][0..14],vls[j],option);
  else
    for (i=0; i<sizeof(mud); i++)
      sorted += format_info(mud[i][0..14],vls[i],option);

  if( args ) sorted=regexp( sorted, args );
  if( !sizeof(sorted) ) {
      write (wrap ("抱歉, 您所下的參數 `"+args+"' 目前在泥網中並沒有符合的MUD列表. 請稍後再試。\n"));    
      return 1;
  }
  result += sort_array(sorted,"compare_names",this_object());
  output = implode(result,"\n");
  this_player()->start_more(output);

  return 1;
}

int compare_names(string a,string b)
{
  return strcmp(a,b);
}
int help()
{
	write( SYNTAX + "\n"+ @HELP_DOC
  這個指令讓你列出目前在Intermud 3 network中跟這個 Mud 取得聯繫的其他 Mud。
  您也可以在 mudlist 後面用關鍵字(注意大小寫差異)當作參數來搜尋符合的項目。

  (*)列表中的旗標分別代表 Tell, Who, Finger, Locate, Channel, News, Mail

  關於 Intermud 3 network 協定的進一步說明請參考以下連結:

	http://www.imaginary.com/protocols/intermud3.html

HELP_DOC
	);
	return 1;
}
