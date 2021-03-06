// xcp.c 
// write by JackyBoy@CuteRabbit Studio for SDXL & CCTX 1999/6/1
// 為了避免遞歸太深，請不要設置進入級別超過16級. JackyBoy
// Tips:為了不影響可以連續發命令，X系列命令可以將遞歸進行call_out調用！
//      但這只是想法我自己并未去實現它!

inherit F_CLEAN_UP;
int help();
int do_cp(string,string,string,int);
string resolvePath(string,int);
int main(object me, string arg)
{
	string  path,wild,dest;
	int level;
	level=15;
	seteuid(geteuid(me));
	write("X c 命令 v0.1  \nWrite By JackyBoy@CuteRabbit for CCTX & SDXL 1999/6/1\n"+
		"主頁：http://mud.yn.cninfo.net/jackyboy\n郵件：jackyboy@126.com\n");
    if (!arg) return help();
    if (sscanf(arg,"-d %s %s",path,dest)!=2)
    {
    	if(sscanf(arg,"-d%d %s %s",level,path,dest)!=3)
    		if(sscanf(arg,"%s %s",path,dest)!=2)
    		{
    			write ("\n參數解析錯誤。\n\n");
    			return help();
    		}
    }
    else
    	level=15;//帶-d參數默認級別為所有級
    if(level<0) level=1;
    if(level>15) level=15;
    dest=resolve_path(me->query("cwd"),dest);
    //處理path分解出wild
    path=resolve_path(me->query("cwd"),path);
    write("未解析路徑：\t"+path+"\n");
    //write("欲復制的目的路徑：\t"+dest+"\n");
    write("搜索目錄級別：\t"+level+"\n");
    wild=resolvePath(path,0);
    path=resolvePath(path,1);
    write("解析后路徑：\t"+path+"\n");
    write("解析后通配符：\t"+wild+"\n");
    write("解析后目標路徑：\t"+dest+"\n\n");
    do_cp(path,wild,dest,level);
    write("\n復制結束。\n");
    return 1;
}

string resolvePath(string path,int op)
{
	string *dn,tmp;
	int i;
	if(path=="/")//對這個情況特殊處理
		return (op)?"/":"*";
	dn=explode(path,"/");
	if(op)//op為非0表示需要返回路徑
	{
		//dn=dn-({dn[sizeof(dn)-1]});
		//tmp=implode(dn,"/")+"/";
		//上面的程序不好，不能對同名路徑正確處理，比如不能在/log/log文件里搜索
		tmp="/";
		for(i=0;i<sizeof(dn)-1;i++)
		{
			//write("合并"+dn[i]+"\n");
			tmp+=dn[i]+"/";
		}
		return tmp;
	}
	else
		return dn[sizeof(dn)-1];
}
int do_cp(string path,string wild,string dest,int level)
{
	//int i;string *fs;
	string file;
	reset_eval_cost();//重新設置剩余執行時間，必須設置！
	if(dest[sizeof(dest)-1]!='/')//這句必不可少，不然就不能正確生成目標路徑
    	dest=dest+"/";
	if(this_player()->query("env/debug"))
		write("開始復制"+path+wild+"到"+dest+"\n");
	if(level<0)
	{
		//write("級別限制，不能再進入。\n");
		return 0;
	}
	
	foreach(file in get_dir(path+wild))
	{

		if(file=="."||file=="..")
			continue;
		
		switch(file_size(path+file))
		{
			case -1:
				//無法讀取該目錄，跳過
				break;
			case -2:
				if(file!="."&&file!="..")
					do_cp(path+file+"/","*",dest+file+"/",level-1);
				break;
			default:
				assure_file(dest+file);
				//write("復制文件："+path+file+"到"+dest+file+"\n");
				cp(path+file,dest+file);
		}
		
	}
	return 1;
}

int help()
{
  write(@HELP

X cp 命令 v0.1  Write By JackyBoy@CuteRabbit for CCTX & SDXL 1999/6/2
主頁：http://mud.yn.cninfo.net/jackyboy
郵件：jackyboy@126.com


指令格式 : xcp [-d[0-15]] 源路徑或文件 目標路徑
此指令可讓你把指定的目錄或文件復制到指定的目錄去。
支持通配符，可以指定復制一定的目錄深度。
HELP
    );
    return 1;
}
