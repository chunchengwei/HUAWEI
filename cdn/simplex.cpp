#include"simplex.h"
#include"graph.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<list>
#include<ctime>
#include<math.h>
using namespace std;

calculator::calculator(GRAPH graph)
{
  cost = graph.FEE;
  limit = graph.BANDWIDTH;
  demand = graph.REQUIREMENT;
  node = graph.FLOWOUT;
  dp_server = graph.scost;
  n_cnode = graph.nCnode;
  node_max.resize(demand.size());
//  node_sort.resize(demand.size());
//  node_sort.push_back(0);
  _AllDemand = 0;
  set<int> server;
  vector<int> answer;
  set<int> UnUsedCnode, UnUsedNode;
  _mincost = n_cnode * dp_server;
//
  _server.clear();
  _server.insert(0);
  _server.insert(1);
  _server.insert(24);
  _minfee(_server, FLOWS);
//
/*
  int money;
  for (unsigned i=0; i<node_max.size(); i++)
  {
    // calculat max flow of node
    node_max[i] = demand[i];
    for (unsigned j=0; j<node[i].size(); j++)
      node_max[i] = node_max[i] + limit[node[i][j]];
    
    // sort node
    node_sort.push_back(i);
    for (unsigned j=0; j<i; j++)
    {
      vector< unsigned >::iterator it;
      it=node_sort.begin();
      if (node_max[i] > node_max[node_sort[j]])
      {
        node_sort.insert(it+j,i);
        node_sort.pop_back();
        break;
      }
    }

    // sum all demand
    _AllDemand = _AllDemand + demand[i];

    // initial unusednode
    UnUsedNode.insert(i);
    if ( demand[i] ==0)
      UnUsedCnode.insert(i);
  }

  for (unsigned i = 0; i < node_sort.size(); i++)
  {
    if (demand[node_sort[i]] != 0)
    {
      Cnode_sort.push_back(node_sort[i]);
    }
  }

  
  int tmp = 0;
//  cout << " consumption node order:" << endl;
  for (unsigned i = 0; i < Cnode_sort.size(); i++)
  {
//    cout << Cnode_sort[i] << " ";
    tmp = tmp + node_max[Cnode_sort[i]];
    if (tmp > _AllDemand)
    {
      _Nleast = i+1;
      break;
    }
    server.insert(Cnode_sort[i]);
    UnUsedNode.erase(Cnode_sort[i]);
    UnUsedCnode.erase(Cnode_sort[i]);
  }


  unsigned dn = Cnode_sort.size();
  cout << "N least is:" << _Nleast << endl;
  for (unsigned i = _Nleast; i < dn; i++)
  {
    cout << "i is:" << i << endl;
    int j = 0;
    for (set<int>::iterator it = UnUsedNode.begin(); it != UnUsedNode.end(); it++)
    {
//      cout << "I am here." << endl;
      j++;
      cout << "j is:" << j << " ";
      _schema.push_back(server);
      _schema.back().insert(*it);
      money = _minfee(_schema.back(), answer);

      if (money != -1)
      {
        if (money < _mincost)
        {
          _mincost = money;
          FLOWS = answer;
          _server = _schema.back();
          dn = _mincost / dp_server;
          cout << "dn is:" << dn << endl;
          if ( _schema.back() != _schema.front() )
          {
            _schema.erase(_schema.end() - 2);

          }
          else
          {
            _schema.push_back(_schema.back());
          }
        }
        else
        {
          _schema.pop_back();
        }

//        cout << "node is :" << *it << endl;
//        cout << "money is :" << money << endl;
//        cout << "server size is :" << _schema.back().size() << endl;
//        for (set<int>::iterator it = _schema.back().begin(); it != _schema.back().end(); it++)
//          cout << *it << " ";
//        cout << endl;
      }
      else
      {
        _schema.pop_back();
      }
    }
//    if(!_schema.empty())
//    {
//      server.clear();
//      server = _schema.back();
//    }
    server.insert(Cnode_sort[i]);
    UnUsedCnode.erase(Cnode_sort[i]);
  }
//  
    if (server.size() == Cnode_sort.size())
    {
      _server = server;
      FLOWS = answer;
    }

    cout << endl;
    cout << "minfee is :" << _mincost << endl;
    cout << "server size is :" << _server.size() << endl;
    for (set<int>::iterator it = _server.begin(); it != _server.end(); it++)
      cout << *it << " ";

    cout << endl;
//
  if(!_schema.empty())
  {
    server = _schema.back();
    server.insert(Cnode_sort[_schema.back().size()-1]);
    if (server != _schema.back())
      _schema.push_back(server);
  }

  server.clear();
  for (unsigned i = 0; i< (rand()%dn); i++)
    server.insert(Cnode_sort[i]);

  _schema.push_back(server);

  cout << "schema size is :" << _schema.size() << endl;
  for (unsigned i = 0; i< _schema.size(); i++)
  {
    cout << i << "th server is:" << endl;
    for (set<int>::iterator it =_schema[i].begin(); it != _schema[i].end(); it++)
      cout << *it  << " ";

    cout << endl;
    _annealing(_schema[i]);

  }

*/
  for (set<int>::iterator it = _server.begin(); it != _server.end(); it++)
    SNODES.push_back(*it);
    
  

//  cout << "n least is:" << _Nleast << endl;
//  cout << "n least fee is:" << _minfee(server, FLOWS) << endl;


/*  server.clear();
  int d = 0;
  for(unsigned i=0; i<demand.size(); i++)
  {
    if (demand[i] != 0)
      SNODES.push_back(i);
  }

  for(int i = _Nleast; i < n_cnode; i++)
  {
    while ( d < 30)
    {
      d++;
      _server(i,server);
      money = _minfee(server, FLOWS);
      cout << money << endl;
      if (money == -1)
      {
        cout << "error" << endl;
//      continue;
      }
      else if ( money < min)
      {
        min = money;
        SNODES.clear();
        for (set<int>::iterator it=server.begin(); it!= server.end(); ++it)
          SNODES.push_back(*it);

        cout << min << endl;
      }
    }
  }
*/

}



bool calculator::_findar (set<unsigned> ar, vector<unsigned> Cb)
{
  set<unsigned> tmp(ar);
  for (vector<unsigned>::size_type ix=0; ix!=Cb.size(); ++ix)
  {
    for (set<unsigned>::iterator it=tmp.begin(); it!=tmp.end(); ++it)
      if(Cb[ix] == *it)
      {
        return true;
      }
  }
  return false;
}

void calculator::_annealing(set<int> &server)
{
  set<int> NUnode, NUnode_new, server_new;
  set<int>::iterator it;
  vector<int> answer, answer_new;
  int n_node = demand.size();
  double Tmin = 3.0;
  double T = 1000.0 * dp_server * n_cnode;
  double delta = 0.9;
  int P_L = 0;
  int P_F = 0;
  int limit = 50;
  int OLOOP = 1000;
  int in, out, ne, ni;
  int fee, newfee ;
  for (int i = 0; i< n_node; i++)
  {
    if ( server.find(i) == server.end() )
    {
      NUnode.insert(i);
    }
  }
  if (_minfee(server, answer) != -1)
    fee = _minfee(server, answer);
  else
  {
    fee = dp_server * n_cnode;
  }

  int ns = server.size();
  int nu = NUnode.size();
  while ( T > Tmin )
  {
    for(int i = 0; i < nu; i++)    //内循环，寻找在一定温度下的最优值
    {
      server_new = server;
      NUnode_new = NUnode;
      ne = floor (rand() % ns);
      ni = floor (rand() % nu);
      it = server_new.begin();
      for (int i = 0; i< ne; i++)
        it ++ ;

      out = *it;
      it = NUnode_new.begin();
      for (int i = 0; i< ni; i++)
        it ++ ;

      in = *it;
      server_new.erase(out);
      server_new.insert(in);
      NUnode_new.erase(in);
      NUnode_new.insert(out);
      newfee = _minfee(server_new, answer_new);
      if ( newfee != -1 )
      {
        double dE = newfee - fee;
        if(dE < 0)
        {
          fee = newfee;
          NUnode = NUnode_new;
          server = server_new;
          answer = answer_new;
          cout << "newfee is :" << fee << endl;
          cout << "server size is :" << server.size() << endl;
          for (set<int>::iterator it = server.begin(); it != server.end(); it++)
            cout << *it << " ";

          cout << endl;
          P_L = 0;
          P_F = 0;
        }
        else
        {
          double rd = rand() / (RAND_MAX + 1.0);
          cout << "rd is: " << rd << endl;
          if(exp(-dE/T) > rd && exp(-dE/T) < 1)
          {
            fee = newfee;
            NUnode = NUnode_new;
            server = server_new;
            answer = answer_new;
            cout << "newfee is :" << fee << endl;
            cout << "server size is :" << server.size() << endl;
            for (set<int>::iterator it = server.begin(); it != server.end(); it++)
              cout << *it << " ";

            cout << endl;
          }
          P_L++;
        }
        if(P_L > limit)
        {
          P_F++;
          break;
        }
      }
   }

   if(fee < _mincost)
   {
     _mincost = fee;
     _server = server;
     FLOWS = answer;
   }

   if(P_F > OLOOP )
     break;

   T = T * delta ;
 }

    cout << endl;
    cout << "minfee is :" << _mincost << endl;
    cout << "server size is :" << _server.size() << endl;
    for (set<int>::iterator it = _server.begin(); it != _server.end(); it++)
      cout << *it << " ";

    cout << endl;

}

int calculator::_minfee (set<int> &server, vector<int> &answer)
{
  unsigned n_server = server.size();
  unsigned n_arc = cost.size();
  unsigned n_node = demand.size();

  vector<int> Cj, b;
  vector<unsigned> Cb;
  vector< vector<int> > matrixA;
  Cj.resize(2*n_arc+n_node);
  b.resize(n_arc+n_node);
  matrixA.resize(n_arc+n_node);
  answer.resize(n_arc);
//
  set<unsigned> Artifical, NCb;        // 人工变量指标 基变量指标 非基变量指标(非基变量永不包含人工变量)
//
  bool ArIndex;
  unsigned Out, In;
  double sigma = 0.0;
  double theta = 1e20;
  double tmp;


  for (unsigned i = 0; i < n_arc+n_node; i++)
  {
    Cb.push_back(i);
    matrixA[i].resize(2*n_arc+n_node);
  }


  for (unsigned i = 0; i < n_arc; i++)       //带宽约束条件
  {
    matrixA[i][i] = 1;
    matrixA[i][i+n_node+n_arc] = 1;
    b[i] = 1 * limit[i];
  }

  for (unsigned i = 0; i < n_node; i++)    //节点流守恒条件
  {
    Artifical.insert(n_arc+i);             //将0~n_node-1设置为人工变量
    matrixA[i+n_arc][i+n_arc] = 1;
    for (unsigned ix = 0; ix < node[i].size(); ++ix)
    {
      matrixA[n_arc+i][n_arc+n_node+node[i][ix]] = -1;
      matrixA[n_arc+i][n_arc+n_node+n_arc-node[i][ix]-1] = 1;
    }
    b[n_arc+i] = demand[i];
  }
  

  for (set<int>::iterator it=server.begin(); it!= server.end(); ++it)
  {
    Artifical.erase(n_arc + (*it));        // 人工变量中排除服务器节点
  }

  for (unsigned i = 0; i < n_arc; i++)
  {
    Cj[i+n_arc+n_node] = -1.0 * cost[i];      // 添负号转化为最大值问题
    NCb.insert(i+n_arc+n_node);
  }

  for (set<unsigned>::iterator it=Artifical.begin(); it!=Artifical.end(); ++it)
  {
    Cj[*it] = -500000;         // 500000 is the Big M.
  }
  Out = 0;
  In = 0;

  while(1)
  {
    ArIndex = _findar(Artifical, Cb);
    sigma = 0.0;
    for (set<unsigned>::iterator it=NCb.begin(); it!=NCb.end(); it++)
    {
      tmp = Cj[*it];
      for (vector<unsigned>::size_type ix=0; ix!=Cb.size(); ++ix)
      {
        tmp = tmp - Cj[Cb[ix]] * matrixA[ix][*it];
      }

      if (tmp >= sigma)
      {
        sigma = tmp;
        In = *it;
      }
    }

    if (sigma <= 0)
    {
      if(ArIndex)
        return -1;
      break;
    }
    else
    {
      theta = 1e20;
      bool flag = 1;
      for (unsigned i = 0; i<n_arc+n_node; i++)
      {
        if (matrixA[i][In] > 0)
        {
          flag = 0;
          tmp = b[i]/matrixA[i][In];
          if (tmp == 0)
          {
            Out = i;
            break;
          }
          if (tmp < theta)
          {
            theta = tmp;
            Out = i;
          }
        }
      }
      if (flag)
        return -1;
    }

    NCb.insert(Cb[Out]);
    NCb.erase(In);
    Cb[Out] = In;
    double multi = 1/matrixA[Out][In];
      
    for (unsigned j = 0; j < 2*n_arc+n_node; j++)
      matrixA[Out][j] = matrixA[Out][j]*multi;

    b[Out] = b[Out]*multi;
          
    for (unsigned i = 0; i < Out; i++)
    {
      multi = matrixA[i][In];
      b[i] = b[i] - b[Out] * multi;
      for (unsigned j = 0; j < 2*n_arc+n_node; j++)
        matrixA[i][j] = matrixA[i][j] - matrixA[Out][j]*multi;
    }
      
    for (unsigned i = Out+1; i < n_arc+n_node; i++)
    {
      multi = matrixA[i][In];
      b[i] = b[i] - b[Out] * multi;
      for (unsigned j = 0; j < 2*n_arc+n_node; j++)
        matrixA[i][j] = matrixA[i][j] - matrixA[Out][j]*multi;
    }
    
  }


  for (unsigned i=0; i< n_arc+n_node; i++)
  {
    if (Cb[i] < n_arc)
    {
      answer[Cb[i]] = limit[Cb[i]] - b[i];
    }
    else if (Cb[i] >= n_arc+n_node)
    {
      answer[Cb[i]-n_arc-n_node] = b[i];
    }
    else
    {
      set<int>:: iterator it;
      it = find( server.begin(), server.end(), Cb[i]-n_arc );
      if (it == server.end())
      {
        cout << "There is Artifical Variable." << endl;
        return -1;
      }
    }
  }

 
  int total = n_server * dp_server;
  for (unsigned i=0; i< n_arc; i++)
    total = total + answer[i]*cost[i];


  return total;
}


