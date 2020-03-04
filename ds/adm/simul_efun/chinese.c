
string chinese_number(int i)
{
	return CHINESE_D->chinese_number(i);
}

string to_chinese(string str)
{
	return CHINESE_D->chinese(str);
}

int is_chinese(string str)
{
	if( strlen(str)>=2 && str[0] > 160 && str[0] < 255 ) return 1;
	return 0;
}
string break_chinese_string(string str, int len, mixed indent)
{
    string indent_str;
    int cntr;

    if( !stringp(str) ) return 0;

    if( intp(indent) ) indent_str = sprintf("%*s", indent, " ");
    else if( stringp(indent) ) indent_str = indent;
    else indent_str = "";

    cntr = 0;

    // strip all newlines.
    str = replace_string(str, "\n", "");

    while( strlen(str) > cntr + len ) {
        int br, i;
        for(i=0; i<len;) {
            if( is_chinese(str[cntr+i..<1]) ) {
                br = cntr+i;
                i++;
            }
            if( str[cntr+i]==' ' )
                br = cntr+i;
            i++;
        }
        cntr+=i;
        str = str[0..br-1] + "\n" + indent_str + str[br..<1];
    }
    return str;
}

