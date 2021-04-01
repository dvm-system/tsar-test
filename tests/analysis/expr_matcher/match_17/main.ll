; ModuleID = 'C:\Users\weaut\Documents\GitHub\tsar-test-dev\tests\analysis\expr_matcher\match_17\main.c'
source_filename = "C:\\Users\\weaut\\Documents\\GitHub\\tsar-test-dev\\tests\\analysis\\expr_matcher\\match_17\\main.c"
target datalayout = "e-m:w-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-windows-msvc19.28.29334"

; Function Attrs: nounwind uwtable
define dso_local i32 @boo(i32* %A) #0 !dbg !8 {
entry:
  %A.addr = alloca i32*, align 8
  %sum = alloca i32, align 4
  %square_sum = alloca i32, align 4
  %index = alloca i32, align 4
  %i = alloca i32, align 4
  %cleanup.dest.slot = alloca i32, align 4
  %j = alloca i32, align 4
  store i32* %A, i32** %A.addr, align 8, !tbaa !25
  call void @llvm.dbg.declare(metadata i32** %A.addr, metadata !15, metadata !DIExpression()), !dbg !29
  %0 = bitcast i32* %sum to i8*, !dbg !30
  call void @llvm.lifetime.start.p0i8(i64 4, i8* %0) #3, !dbg !30
  call void @llvm.dbg.declare(metadata i32* %sum, metadata !16, metadata !DIExpression()), !dbg !31
  store i32 0, i32* %sum, align 4, !dbg !31, !tbaa !32
  %1 = bitcast i32* %square_sum to i8*, !dbg !30
  call void @llvm.lifetime.start.p0i8(i64 4, i8* %1) #3, !dbg !30
  call void @llvm.dbg.declare(metadata i32* %square_sum, metadata !17, metadata !DIExpression()), !dbg !34
  store i32 0, i32* %square_sum, align 4, !dbg !34, !tbaa !32
  %2 = bitcast i32* %index to i8*, !dbg !30
  call void @llvm.lifetime.start.p0i8(i64 4, i8* %2) #3, !dbg !30
  call void @llvm.dbg.declare(metadata i32* %index, metadata !18, metadata !DIExpression()), !dbg !35
  %3 = bitcast i32* %i to i8*, !dbg !36
  call void @llvm.lifetime.start.p0i8(i64 4, i8* %3) #3, !dbg !36
  call void @llvm.dbg.declare(metadata i32* %i, metadata !19, metadata !DIExpression()), !dbg !37
  store i32 0, i32* %i, align 4, !dbg !37, !tbaa !32
  br label %for.cond, !dbg !36

for.cond:                                         ; preds = %for.inc16, %entry
  %4 = load i32, i32* %i, align 4, !dbg !38, !tbaa !32
  %cmp = icmp slt i32 %4, 100, !dbg !39
  br i1 %cmp, label %for.body, label %for.cond.cleanup, !dbg !40

for.cond.cleanup:                                 ; preds = %for.cond
  store i32 2, i32* %cleanup.dest.slot, align 4
  %5 = bitcast i32* %i to i8*, !dbg !41
  call void @llvm.lifetime.end.p0i8(i64 4, i8* %5) #3, !dbg !41
  br label %for.end18

for.body:                                         ; preds = %for.cond
  %6 = bitcast i32* %j to i8*, !dbg !42
  call void @llvm.lifetime.start.p0i8(i64 4, i8* %6) #3, !dbg !42
  call void @llvm.dbg.declare(metadata i32* %j, metadata !21, metadata !DIExpression()), !dbg !43
  store i32 0, i32* %j, align 4, !dbg !43, !tbaa !32
  br label %for.cond1, !dbg !42

for.cond1:                                        ; preds = %for.inc, %for.body
  %7 = load i32, i32* %j, align 4, !dbg !44, !tbaa !32
  %cmp2 = icmp slt i32 %7, 100, !dbg !46
  br i1 %cmp2, label %for.body4, label %for.cond.cleanup3, !dbg !47

for.cond.cleanup3:                                ; preds = %for.cond1
  store i32 5, i32* %cleanup.dest.slot, align 4
  %8 = bitcast i32* %j to i8*, !dbg !48
  call void @llvm.lifetime.end.p0i8(i64 4, i8* %8) #3, !dbg !48
  br label %for.end

for.body4:                                        ; preds = %for.cond1
  %9 = load i32, i32* %i, align 4, !dbg !49, !tbaa !32
  %mul = mul nsw i32 %9, 100, !dbg !51
  %10 = load i32, i32* %j, align 4, !dbg !52, !tbaa !32
  %add = add nsw i32 %mul, %10, !dbg !53
  store i32 %add, i32* %index, align 4, !dbg !54, !tbaa !32
  %11 = load i32*, i32** %A.addr, align 8, !dbg !55, !tbaa !25
  %12 = load i32, i32* %index, align 4, !dbg !56, !tbaa !32
  %idxprom = sext i32 %12 to i64, !dbg !55
  %arrayidx = getelementptr inbounds i32, i32* %11, i64 %idxprom, !dbg !55
  %13 = load i32, i32* %arrayidx, align 4, !dbg !55, !tbaa !32
  %14 = load i32, i32* %sum, align 4, !dbg !57, !tbaa !32
  %add5 = add nsw i32 %14, %13, !dbg !57
  store i32 %add5, i32* %sum, align 4, !dbg !57, !tbaa !32
  %15 = load i32*, i32** %A.addr, align 8, !dbg !58, !tbaa !25
  %16 = load i32, i32* %index, align 4, !dbg !59, !tbaa !32
  %idxprom6 = sext i32 %16 to i64, !dbg !58
  %arrayidx7 = getelementptr inbounds i32, i32* %15, i64 %idxprom6, !dbg !58
  %17 = load i32, i32* %arrayidx7, align 4, !dbg !58, !tbaa !32
  %18 = load i32*, i32** %A.addr, align 8, !dbg !60, !tbaa !25
  %19 = load i32, i32* %index, align 4, !dbg !61, !tbaa !32
  %idxprom8 = sext i32 %19 to i64, !dbg !60
  %arrayidx9 = getelementptr inbounds i32, i32* %18, i64 %idxprom8, !dbg !60
  %20 = load i32, i32* %arrayidx9, align 4, !dbg !60, !tbaa !32
  %mul10 = mul nsw i32 %17, %20, !dbg !62
  %21 = load i32*, i32** %A.addr, align 8, !dbg !63, !tbaa !25
  %22 = load i32, i32* %index, align 4, !dbg !64, !tbaa !32
  %idxprom11 = sext i32 %22 to i64, !dbg !63
  %arrayidx12 = getelementptr inbounds i32, i32* %21, i64 %idxprom11, !dbg !63
  store i32 %mul10, i32* %arrayidx12, align 4, !dbg !65, !tbaa !32
  %23 = load i32*, i32** %A.addr, align 8, !dbg !66, !tbaa !25
  %24 = load i32, i32* %index, align 4, !dbg !67, !tbaa !32
  %idxprom13 = sext i32 %24 to i64, !dbg !66
  %arrayidx14 = getelementptr inbounds i32, i32* %23, i64 %idxprom13, !dbg !66
  %25 = load i32, i32* %arrayidx14, align 4, !dbg !66, !tbaa !32
  %26 = load i32, i32* %square_sum, align 4, !dbg !68, !tbaa !32
  %add15 = add nsw i32 %26, %25, !dbg !68
  store i32 %add15, i32* %square_sum, align 4, !dbg !68, !tbaa !32
  br label %for.inc, !dbg !69

for.inc:                                          ; preds = %for.body4
  %27 = load i32, i32* %j, align 4, !dbg !70, !tbaa !32
  %inc = add nsw i32 %27, 1, !dbg !70
  store i32 %inc, i32* %j, align 4, !dbg !70, !tbaa !32
  br label %for.cond1, !dbg !48, !llvm.loop !71

for.end:                                          ; preds = %for.cond.cleanup3
  br label %for.inc16, !dbg !74

for.inc16:                                        ; preds = %for.end
  %28 = load i32, i32* %i, align 4, !dbg !75, !tbaa !32
  %inc17 = add nsw i32 %28, 1, !dbg !75
  store i32 %inc17, i32* %i, align 4, !dbg !75, !tbaa !32
  br label %for.cond, !dbg !41, !llvm.loop !76

for.end18:                                        ; preds = %for.cond.cleanup
  %29 = load i32, i32* %sum, align 4, !dbg !78, !tbaa !32
  %30 = load i32, i32* %square_sum, align 4, !dbg !79, !tbaa !32
  %mul19 = mul nsw i32 %29, %30, !dbg !80
  store i32 1, i32* %cleanup.dest.slot, align 4
  %31 = bitcast i32* %index to i8*, !dbg !81
  call void @llvm.lifetime.end.p0i8(i64 4, i8* %31) #3, !dbg !81
  %32 = bitcast i32* %square_sum to i8*, !dbg !81
  call void @llvm.lifetime.end.p0i8(i64 4, i8* %32) #3, !dbg !81
  %33 = bitcast i32* %sum to i8*, !dbg !81
  call void @llvm.lifetime.end.p0i8(i64 4, i8* %33) #3, !dbg !81
  ret i32 %mul19, !dbg !82
}

; Function Attrs: nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: argmemonly nounwind willreturn
declare void @llvm.lifetime.start.p0i8(i64 immarg, i8* nocapture) #2

; Function Attrs: argmemonly nounwind willreturn
declare void @llvm.lifetime.end.p0i8(i64 immarg, i8* nocapture) #2

attributes #0 = { nounwind uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone speculatable willreturn }
attributes #2 = { argmemonly nounwind willreturn }
attributes #3 = { nounwind }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!3, !4, !5, !6}
!llvm.ident = !{!7}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 11.0.0 (https://github.com/llvm/llvm-project.git 81eb1c1fa75c6407713b5657156d8d9149572bfe)", isOptimized: true, runtimeVersion: 0, emissionKind: FullDebug, enums: !2, nameTableKind: None)
!1 = !DIFile(filename: "C:\\Users\\weaut\\Documents\\GitHub\\tsar-test-dev\\tests\\analysis\\expr_matcher\\match_17\\main.c", directory: "C:\\Users\\weaut", checksumkind: CSK_MD5, checksum: "6a6efa42ccbaf3c784a1803ed53b1f9b")
!2 = !{}
!3 = !{i32 2, !"CodeView", i32 1}
!4 = !{i32 2, !"Debug Info Version", i32 3}
!5 = !{i32 1, !"wchar_size", i32 2}
!6 = !{i32 7, !"PIC Level", i32 2}
!7 = !{!"clang version 11.0.0 (https://github.com/llvm/llvm-project.git 81eb1c1fa75c6407713b5657156d8d9149572bfe)"}
!8 = distinct !DISubprogram(name: "boo", scope: !9, file: !9, line: 3, type: !10, scopeLine: 3, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition | DISPFlagOptimized, unit: !0, retainedNodes: !14)
!9 = !DIFile(filename: "Documents\\GitHub\\tsar-test-dev\\tests\\analysis\\expr_matcher\\match_17\\main.c", directory: "C:\\Users\\weaut", checksumkind: CSK_MD5, checksum: "6a6efa42ccbaf3c784a1803ed53b1f9b")
!10 = !DISubroutineType(types: !11)
!11 = !{!12, !13}
!12 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!13 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !12, size: 64)
!14 = !{!15, !16, !17, !18, !19, !21}
!15 = !DILocalVariable(name: "A", arg: 1, scope: !8, file: !9, line: 3, type: !13)
!16 = !DILocalVariable(name: "sum", scope: !8, file: !9, line: 4, type: !12)
!17 = !DILocalVariable(name: "square_sum", scope: !8, file: !9, line: 4, type: !12)
!18 = !DILocalVariable(name: "index", scope: !8, file: !9, line: 4, type: !12)
!19 = !DILocalVariable(name: "i", scope: !20, file: !9, line: 5, type: !12)
!20 = distinct !DILexicalBlock(scope: !8, file: !9, line: 5, column: 3)
!21 = !DILocalVariable(name: "j", scope: !22, file: !9, line: 6, type: !12)
!22 = distinct !DILexicalBlock(scope: !23, file: !9, line: 6, column: 5)
!23 = distinct !DILexicalBlock(scope: !24, file: !9, line: 5, column: 31)
!24 = distinct !DILexicalBlock(scope: !20, file: !9, line: 5, column: 3)
!25 = !{!26, !26, i64 0}
!26 = !{!"any pointer", !27, i64 0}
!27 = !{!"omnipotent char", !28, i64 0}
!28 = !{!"Simple C/C++ TBAA"}
!29 = !DILocation(line: 3, column: 14, scope: !8)
!30 = !DILocation(line: 4, column: 3, scope: !8)
!31 = !DILocation(line: 4, column: 7, scope: !8)
!32 = !{!33, !33, i64 0}
!33 = !{!"int", !27, i64 0}
!34 = !DILocation(line: 4, column: 16, scope: !8)
!35 = !DILocation(line: 4, column: 32, scope: !8)
!36 = !DILocation(line: 5, column: 8, scope: !20)
!37 = !DILocation(line: 5, column: 12, scope: !20)
!38 = !DILocation(line: 5, column: 19, scope: !24)
!39 = !DILocation(line: 5, column: 21, scope: !24)
!40 = !DILocation(line: 5, column: 3, scope: !20)
!41 = !DILocation(line: 5, column: 3, scope: !24)
!42 = !DILocation(line: 6, column: 10, scope: !22)
!43 = !DILocation(line: 6, column: 14, scope: !22)
!44 = !DILocation(line: 6, column: 21, scope: !45)
!45 = distinct !DILexicalBlock(scope: !22, file: !9, line: 6, column: 5)
!46 = !DILocation(line: 6, column: 23, scope: !45)
!47 = !DILocation(line: 6, column: 5, scope: !22)
!48 = !DILocation(line: 6, column: 5, scope: !45)
!49 = !DILocation(line: 7, column: 15, scope: !50)
!50 = distinct !DILexicalBlock(scope: !45, file: !9, line: 6, column: 33)
!51 = !DILocation(line: 7, column: 17, scope: !50)
!52 = !DILocation(line: 7, column: 23, scope: !50)
!53 = !DILocation(line: 7, column: 21, scope: !50)
!54 = !DILocation(line: 7, column: 13, scope: !50)
!55 = !DILocation(line: 8, column: 14, scope: !50)
!56 = !DILocation(line: 8, column: 16, scope: !50)
!57 = !DILocation(line: 8, column: 11, scope: !50)
!58 = !DILocation(line: 9, column: 18, scope: !50)
!59 = !DILocation(line: 9, column: 20, scope: !50)
!60 = !DILocation(line: 9, column: 29, scope: !50)
!61 = !DILocation(line: 9, column: 31, scope: !50)
!62 = !DILocation(line: 9, column: 27, scope: !50)
!63 = !DILocation(line: 9, column: 7, scope: !50)
!64 = !DILocation(line: 9, column: 9, scope: !50)
!65 = !DILocation(line: 9, column: 16, scope: !50)
!66 = !DILocation(line: 10, column: 21, scope: !50)
!67 = !DILocation(line: 10, column: 23, scope: !50)
!68 = !DILocation(line: 10, column: 18, scope: !50)
!69 = !DILocation(line: 11, column: 5, scope: !50)
!70 = !DILocation(line: 6, column: 28, scope: !45)
!71 = distinct !{!71, !47, !72, !73}
!72 = !DILocation(line: 11, column: 5, scope: !22)
!73 = !{!"llvm.loop.unroll.disable"}
!74 = !DILocation(line: 12, column: 3, scope: !23)
!75 = !DILocation(line: 5, column: 26, scope: !24)
!76 = distinct !{!76, !40, !77, !73}
!77 = !DILocation(line: 12, column: 3, scope: !20)
!78 = !DILocation(line: 13, column: 10, scope: !8)
!79 = !DILocation(line: 13, column: 16, scope: !8)
!80 = !DILocation(line: 13, column: 14, scope: !8)
!81 = !DILocation(line: 14, column: 1, scope: !8)
!82 = !DILocation(line: 13, column: 3, scope: !8)
