#include "treeprocessor.hpp"

void DrawProcessor::processLeaf(const Voxel &voxel)
{
    renderer.draw(voxel.position, voxel.isSolid ? '#' : '|');
}

// todo: implement
void FlattenProcessor::processLeaf(const Voxel &voxel)
{
    // size_t x = Math::hashFunc(voxel.position);
    ourMap[voxel.position] = voxel;
}

using namespace std;
using namespace Math;

// Extracts a single connected model from the map and puts it into the target tree.
// Returns false when the map is already empty, true otherwise.
// todo: implement (first, second)  second -> isSolid / position -> [0,1]
bool extract(VoxelMap &map, QuadTree<Voxel> &target)
{
    if (map.empty())
    {
        return false;
    }
    else
    {
        for (auto v : map)
        {
            int x = v.second.position[0];
            int y = v.second.position[1];
            target.insert(x, y, v.second);
            auto f = map.begin();
            f = map.erase(f);
            break;
        }
        return true;
    }
}

// Extracts all coherent models from the tree and puts them into new trees.
// todo: implement
void extractSubModels(QuadTree<Voxel> &tree, vector<unique_ptr<QuadTree<Voxel>>> &subTrees)
{
    // QuadTree<Voxel> *x = &tree;
    // cout << "assigned X \n";
    // auto _tree = x;
    // cout << "assigned unique_ptr \n";
    auto _tree = new QuadTree<Voxel>();
    subTrees.push_back(unique_ptr<QuadTree<Voxel>>(_tree));
    cout << "Pushed \n";

    auto _tree1 = new QuadTree<Voxel>();

    subTrees.push_back(unique_ptr<QuadTree<Voxel>>(_tree1));
    auto _tree2 = new QuadTree<Voxel>();

    subTrees.push_back(unique_ptr<QuadTree<Voxel>>(_tree2));
    auto _tree3 = new QuadTree<Voxel>();

    subTrees.push_back(unique_ptr<QuadTree<Voxel>>(_tree3));
}

//Bearbeitet bei Abdelhalim Abdelhalim, Abdelrahman Abdelhalim,Youssef Haj Ayed, Mahadik Hannan Javed und Moayad Okal