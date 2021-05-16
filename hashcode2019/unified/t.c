        changes = 0;
        sort(v1+j+1, v1+m, [] (const aset & lhs, const aset & rhs){ return comp(lhs.x) > comp(rhs.x);} );
        for(int i = j + 1; i < m ;++i){
            if(v1[i].u != v2[i].u || v1[i].v != v2[i].v)
                ++changes;
            v2[i].u = v1[i].u;
            v2[i].v = v1[i].v;
        }
        cout << j << ":" << changes << endl;