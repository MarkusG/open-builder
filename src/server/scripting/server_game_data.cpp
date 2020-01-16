#include "server_game_data.h"

#include <common/debug.h>

ServerGameData::ServerGameData()
{
}

void ServerGameData::addVoxel(const sol::table &voxelData)
{
    ServerVoxel voxel;
    voxel.name = voxelData["name"].get<std::string>();

    voxel.isCollidable = voxelData["collidable"].get<bool>();

    voxel.topTexture = voxelData["render"]["top"].get<std::string>();
    voxel.sideTexture = voxelData["render"]["sides"].get<std::string>();
    voxel.bottomTexture = voxelData["render"]["bottom"].get<std::string>();

    voxel.meshStyle = voxelData["render"]["mesh"].get<VoxelMeshStyle>();
    voxel.meshType = voxelData["render"]["type"].get<VoxelType>();
    ;

    m_voxelDataList.push_back(voxel);

    LOGVAR("Server", "Adding block", voxel.name);
}

const VoxelDataList &ServerGameData::voxelData() const
{
    return m_voxelDataList;
}
