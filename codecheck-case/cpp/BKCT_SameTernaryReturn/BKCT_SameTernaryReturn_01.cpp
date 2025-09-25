// defect:bkcheck(SameTernaryReturn)

void bad() {
    // bad
    int A = B ? C : C;
    // bad
    fovRadius[0] = tan(DEG2RAD((rollAngleClamped % 2 == 0 ?
                                cg.refdef.fov_x : cg.refdef.fov_x) * 0.52)) * sdist;
}

unsigned Dasm9900(char *buffer, unsigned pc, int model_id,
                  const UINT8 *oprom, const UINT8 *opram) {
    // ....
    // bad
    buffer += sprintf(buffer, bit_position ? ",(%d," : ",(%d,", bit_position);
    // ....
}

void CGameServer::LagProtection() {
    // ....
    // bad
    const float playerCpuUsage = player.isLocal ? player.cpuUsage : player.cpuUsage; // <=
    // ....
}