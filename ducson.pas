{$MODE OBJFPC}
program nkracing;
uses    math;
type    e=record
        x,y,w:longint;
        end;
const   maxn=10004;
        maxm=100005;
        fi='';
var     res,n,m:longint;
        a:array[1..maxm] of e;
        lab:array[1..maxn] of longint;
        check:array[1..maxm] of boolean;

procedure input;
var     inp:text;
        i:longint;
begin
        assign(inp,fi);reset(inp);
        readln(inp,n,m);
        for i:=1 to m do
        readln(inp,a[i].x,a[i].y,a[i].w);
        close(inp);
end;

procedure sort(l,r:longint);
var     p,i,j:longint;
        t:e;
begin
        if l>=r then exit;
        i:=l;j:=r;
        p:=a[random(r-l+1)+l].w;
        repeat
                while a[i].w>p do inc(i);
                while a[j].w<p do dec(j);
                if i<=j then
                begin
                        if i<j then
                        begin
                                t:=a[i];
                                a[i]:=a[j];
                                a[j]:=t;
                        end;
                        inc(i);dec(j);
                end;
        until i>j;
        sort(l,j);sort(i,r);
end;

function root(u:longint):longint;
begin
        if lab[u]<=0 then exit(u);
        result:=root(lab[u]);
        lab[u]:=result;
end;

procedure union(u,v:longint);
begin
        if lab[u]<lab[v] then lab[v]:=u
        else
        begin
                if lab[u]=lab[v] then dec(lab[v]);
                lab[u]:=v;
        end;
end;

procedure kruskal;
var     i,x,y,c:longint;
begin
        sort(1,m);
        for i:=1 to m do
        begin
                x:=root(a[i].x);
                y:=root(a[i].y);
                if x<>y then
                begin
                        inc(c);
                        check[i]:=true;
                        union(x,y);
                end;
                if c=n-1 then break;
        end;
        for i:=1 to m do if not check[i] then inc(res,a[i].w);
end;

begin
        input;
        kruskal;
        write(res);
end.
