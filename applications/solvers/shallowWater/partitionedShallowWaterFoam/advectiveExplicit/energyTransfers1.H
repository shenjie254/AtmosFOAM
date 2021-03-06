// Potential energy
energyField =  0.5*g*sqr(h);

PE1 = fvc::domainIntegrate(energyField)/Vtot;

// Kinetic energy
energyField *= 0;
delta_ke_face *= 0.;
delta_ke_centre *= 0.;
for(label ip = 0; ip < nParts; ip++)
{
    energyField += 0.5*sigmah[ip]*magSqr(u[ip]);
    delta_ke_face -= 0.5*fvc::interpolate(sigmah[ip])*volFlux[ip]*volFlux[ip];
    delta_ke_centre -= 0.5*sigmah[ip]*magSqr(u[ip]);
}

KE1 = fvc::domainIntegrate(energyField)/Vtot;

E1 = KE1 + PE1;

F1 *= 0;
hu1 *= 0;
for(label ip = 0; ip < nParts; ip++)
{
    F1 += fvc::interpolate(sigmah[ip])*volFlux[ip];
    //F1 += flux[ip];
    hu1 += hu[ip];
}
