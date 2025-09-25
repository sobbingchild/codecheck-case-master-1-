// defect:bkcheck(AssignItself)

void bad_01() {
    dst.m_a = src.m_a;
    // bad
    dst.m_b = dst.m_b;
}

void good() {
    // good
    (foo) = (foo);
}

PassRefPtr <Structure> Structure::
getterSetterTransition(Structure *structure) {
    // ....
    RefPtr <Structure> transition =
            create(structure->storedPrototype(), structure->typeInfo());
    transition->m_propertyStorageCapacity =
            structure->m_propertyStorageCapacity;
    // bad
    transition->m_hasGetterSetterProperties =      // <=
            transition->m_hasGetterSetterProperties;
    transition->m_hasNonEnumerableProperties =
            structure->m_hasNonEnumerableProperties;
    transition->m_specificFunctionThrashCount =
            structure->m_specificFunctionThrashCount;
    // ....
}

class FSlateDrawElement {
    // ....
    FORCEINLINE void SetPosition(const FVector2D &InPosition) {
        // bad
        Position = Position;// The 'Position' variable is assigned to itself.
        // bad
        ResolveParams.CubeFace = (ECubeFace) ResolveParams.CubeFace;
    }

    // ....
    FVector2D Position;
    // ....
};

