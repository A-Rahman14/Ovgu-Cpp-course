#pragma once

#include <unordered_map>
#include <memory>
#include <vector>

#include "renderer.hpp"
#include "data.hpp"
#include "quadtree.hpp"

// tree traverse processor that draws all components with the given renderer
struct DrawProcessor
{
    DrawProcessor(Graphic::Renderer &_renderer) : renderer(_renderer) {}

    void processLeaf(const Voxel &voxel);
    void process(int size, Voxel *voxel) {}

private:
    Graphic::Renderer &renderer;
};

// std::hash<Math::IVec2> hash_my;

// A processor that traverses the tree and adds all leaves to a given VoxelMap.
// todo: implement
typedef std::unordered_map<Math::IVec2, Voxel> VoxelMap;
// todo: Add a specialisation for std::hash.
namespace std
{
    template <>
    struct hash<Math::IVec2>
    {
        size_t operator()(const Math::IVec2 &x) const
        {
            return Math::hashFunc(x);
        }
    };

}

struct FlattenProcessor
{

    FlattenProcessor(VoxelMap &voxelMap) : ourMap(voxelMap) {}
    // Process function that is only called on leaves.
    void processLeaf(const Voxel &voxel);

    // This function is called on every node of the tree.
    // The given size is the level of the node in the tree,
    // where on level 0 the leaves are fonud.
    // This functionality is not needed for this task.
    void process(int size, const Voxel *voxel) {}

private:
    VoxelMap &ourMap;
};

// Extracts a single coherent model from the map and puts it into the target tree.
// Returns false when the map is already empty, true otherwise.
// todo: implement
bool extract(VoxelMap &map, QuadTree<Voxel> &target);

// Extracts all coherent models from the tree and puts them into new trees.
// todo: implement
void extractSubModels(QuadTree<Voxel> &tree, std::vector<std::unique_ptr<QuadTree<Voxel>>> &subTrees);